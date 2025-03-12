import subprocess
import os
from datetime import datetime

# 设置 Git 仓库路径
repo_path = "./"
os.chdir(repo_path)

# 获取当前时间戳
timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")

# Git 添加所有更改
subprocess.run(["git", "add", "."])

# Git 提交
commit_message = f"Auto commit on {timestamp}"
subprocess.run(["git", "commit", "-m", commit_message])

# Git 推送
subprocess.run(["git", "push", "origin", "main"])

print("Git automation completed!")