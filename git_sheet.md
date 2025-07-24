# Offline Git Workflow Cheat Sheet

## 1 Initialize Repo
git init

## 2 Check Status
git status

## 3 Stage Changes
git add <file>      # stage one file
git add .           # stage everything

## 4 Commit
git commit -m "Your commit message"

## 5 See History
git log             # detailed log
git log --oneline   # compact log

## 6 Add Remote (when online)
git remote add origin git@github.com:USERNAME/REPO.git

## 7 Push to Remote
git push -u origin main   # first push
git push                  # later pushes

## 8 Pull Updates (when needed)
git pull

## 9 Undo / Go Back
git log

✅ Commit offline → push when online → stay in control.
