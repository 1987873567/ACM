$OutputEncoding = [Console]::OutputEncoding = New-Object System.Text.UTF8Encoding
# Git 仓库路径
$repoPath = "C:\Data\APP\IDE\ACM\ACM"
$gitRepoURL = "git@github.com:1987873567/ACM.git"
$branch = "main"
$pingURL = "github.com"

$logFile = "C:\Data\APP\IDE\ACM\GitMonitor.log"
$maxSizeMB = 10
$maxSizeBytes = $maxSizeMB * 1024 * 1024

if (Test-Path $logFile) {
    Clear-Content -Path $logFile -Force
} else {
	New-Item -Path $logFile -ItemType File -Force | Out-Null
}


# Log 输出
function Write-Log {
    param([string]$message)
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $file = [System.IO.StreamWriter]::new($logFile, $true, [System.Text.Encoding]::UTF8)
    $file.WriteLine("$timestamp $message")
    $file.Close()
}

# 进程状态函数
function status_ps { param([string]$ps_name) return Get-Process -Name $ps_name -ErrorAction SilentlyContinue }

# 网络状态函数
function status_net { return Test-Connection -ComputerName $pingURL -Count 2 -Quiet }

# 设置 SSH 代理
$env:GIT_SSH = "C:\Program Files\Git\usr\bin\ssh.exe"
Start-Service ssh-agent -ErrorAction SilentlyContinue
Start-Sleep -Seconds 2
ssh-add "$env:USERPROFILE\.ssh\id_rsa" 2>$null

#等待网络
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
if (-Not (Test-Path $repoPath)) { Write-Log "仓库不存在，克隆中..."; git clone $gitRepoURL $repoPath }
else { Write-Log "仓库已存在，拉取最新代码..."; git -C $repoPath pull origin $branch; Write-Log "拉取成功..."}

# 监测进程
$wasRunning = $false

while ($true) {
	if (Test-Path $logFile) {
		if ((Get-Item $logFile).length -gt $maxSizeBytes) {
			Clear-Content -Path $logFile -Force
		}
	}		
    # 监测网络状态
    if (-Not (status_net)) {
        Write-Log "网络不可用，等待重试..."
        Start-Sleep -Seconds 5
        continue
    }
    $retryCount = 0

    # 监测 sublime_text 进程
    $sublimeRunning = status_ps "sublime_text"
    if ($sublimeRunning -ne $null) { $wasRunning = $true }
    elseif ($wasRunning) {
        Write-Log "检测到 sublime 关闭，等待 10 秒后推送代码..."
        Start-Sleep -Seconds 10
        if (status_ps "sublime_text" -ne $null) {Write-Log "检测到sublime_text在继续运行,终止推送..."; continue }

        try {
            # 检查是否有文件改动
            if (git -C $repoPath status --porcelain) {
                Set-Location -Path $repoPath
                git -C $repoPath add .
                git -C $repoPath commit -m "Auto backup on $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
                # 使用 Start-Process 运行 Git Push
                # $process = Start-Process -FilePath "git" -ArgumentList "push", "origin", $branch -PassThru -NoNewWindow -Wait
                $process = Start-Process -FilePath "git" -ArgumentList "-C", $repoPath, "push", "origin", "main" -PassThru -NoNewWindow -Wait
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