# 设置 UTF-8 编码，避免日志乱码
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
$OutputEncoding = [System.Text.Encoding]::UTF8

# Git 仓库路径
$repoPath = "C:\Data\APP\IDE\ACM\ACM"
$gitRepoURL = "git@github.com:1987873567/ACM.git"
$branch = "main"
$pingURL = "github.com"

# 日志文件路径
$logFile = "C:\Data\APP\IDE\ACM\GitMonitor.log"
$maxSizeMB = 10
$maxSizeBytes = $maxSizeMB * 1024 * 1024

# 初始化日志文件
if (Test-Path $logFile) {
    Clear-Content -Path $logFile -Force
} else {
    New-Item -Path $logFile -ItemType File -Force | Out-Null
}

# 记录日志的函数
function Write-Log {
    param([string]$message)
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    Add-Content -Path $logFile -Value "$timestamp $message" -Encoding UTF8
}

# 执行 Git 命令并检查错误
function Run-GitCommand {
	param (
        [string]$repoPath,
        [string[]]$command
    )

    # 判断是否是 `git clone`
    if ($command[0] -eq "clone") {
        $output = & git @command 2>&1
    } else {
        $output = & git -C $repoPath @command 2>&1
    }
    $exitCode = $LASTEXITCODE
    
    # 记录日志
    Add-Content -Path $logFile -Value $output -Encoding UTF8
    if ($exitCode -ne 0) {
        Write-Log "Git 命令执行失败，错误码：$exitCode"
        Write-Log "错误详情：$output"
    }
}

# 进程状态检测
function status_ps { param([string]$ps_name) return Get-Process -Name $ps_name -ErrorAction SilentlyContinue }

# 网络状态检测
function status_net { return Test-Connection -ComputerName $pingURL -Count 2 -Quiet }

# 设置 SSH 代理
$env:GIT_SSH = "C:\Program Files\Git\usr\bin\ssh.exe"
Start-Service ssh-agent -ErrorAction SilentlyContinue
Start-Sleep -Seconds 2
ssh-add "$env:USERPROFILE\.ssh\id_rsa" 2>$null

# 等待网络连接
while ($true) {
    if (-Not (status_net)) {
        Write-Log "网络不可用，等待重试..."
        Start-Sleep -Seconds 5
        continue
    } else {
        break
    }
}

# 确保 Git 可用
if (-not (Get-Command git -ErrorAction SilentlyContinue)) { Write-Log "Git 未安装！"; Exit }

# 初始化 Git 仓库
if (-Not (Test-Path $repoPath)) { 
    Write-Log "仓库不存在，克隆中..."
    Run-GitCommand -RepoPath $repoPath -Command @("clone", $gitRepoURL, $repoPath)
} else { 
    Write-Log "仓库已存在，拉取最新代码..."
    
    # 切换到 Git 仓库目录
    Set-Location -Path $repoPath
    
    # 执行拉取命令
	Run-GitCommand -RepoPath $repoPath -Command @("fetch", "origin")
	Run-GitCommand -RepoPath $repoPath -Command @("reset", "--hard", "origin/main")

    Write-Log "拉取成功！"
}

# 监测进程
$wasRunning = $false

while ($true) {
    if (Test-Path $logFile) {
        if ((Get-Item $logFile).length -gt $maxSizeBytes) {
            Clear-Content -Path $logFile -Force 2>&1 | Out-File -FilePath $logFile -Append -Encoding utf8
        }
    }        

    # 监测网络状态
    if (-Not (status_net)) {
        Write-Log "网络不可用，等待重试..."
        Start-Sleep -Seconds 5
        continue
    }

    # 监测 sublime_text 进程
    $sublimeRunning = status_ps "sublime_text"
    if ($sublimeRunning -ne $null) { $wasRunning = $true }
    elseif ($wasRunning) {
        Write-Log "检测到 Sublime Text 关闭，等待 10 秒后推送代码..."
        Start-Sleep -Seconds 10
        if (status_ps "sublime_text" -ne $null) { Write-Log "检测到 Sublime 继续运行，终止推送..."; continue }

        try {
            # 检查是否有文件改动
            if (git -C $repoPath status --porcelain) {
                Set-Location -Path $repoPath
                Run-GitCommand -RepoPath $repoPath -Command @("add", ".")
                Run-GitCommand -RepoPath $repoPath -Command @("commit", "-m", "Auto backup on $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')")

                # 执行 Git Push
                $process = Start-Process -FilePath "git" -ArgumentList "push origin $branch" -PassThru -NoNewWindow -Wait
                if ($process.ExitCode -eq 0) {
                    Write-Log "Git 推送成功！"
                } else {
                    Write-Log "Git 推送失败，错误码：$($process.ExitCode)"
                }
            } else {
                Write-Log "无更改，无需推送。"
            }
        } catch {
            Write-Log "Git 操作失败！"
        }

        $wasRunning = $false
    }

    Start-Sleep -Seconds 5
}
