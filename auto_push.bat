@echo off
for /f "tokens=2 delims==." %%a in ('wmic os get localdatetime /value') do set datetime=%%a
set current_date=%datetime:~0,8%
git add .
git commit -m "Auto commit on %current_date%"
git push origin main
echo "1987873567\n"
echo "jj102204.@jj.com\n"
pause