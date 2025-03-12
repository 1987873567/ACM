import subprocess
from datetime import datetime

# 设置 Git 仓库路径
repo_path = "C:/Data/APP/IDE/ACM/ACM"

# 切换到仓库目录
subprocess.run(["cd", repo_path], shell=True)

# Git 拉取
subprocess.run(["git", "pull", "origin", "main"])

# Git 添加所有更改
subprocess.run(["git", "add", "."])

# Git 提交
timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
commit_message = f"Auto commit on {timestamp}"
subprocess.run(["git", "commit", "-m", commit_message])

# 设置远程仓库 URL（SSH 格式）
repo_url = "git@github.com:1987873567/ACM.git"
subprocess.run(["git", "remote", "set-url", "origin", repo_url])

# Git 推送
try:
    subprocess.run(["git", "push", "origin", "main"], check=True, input="yes\n", text=True)
except subprocess.CalledProcessError as e:
    print(f"Git push failed: {e}")

print("Git automation completed!")