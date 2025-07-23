# 🚀 Offline Git Workflow Cheat Sheet

## 1️⃣ Initialize Repo
git init

## 2️⃣ Check Status
git status

## 3️⃣ Stage Changes
git add <file>      # stage one file
git add .           # stage everything

## 4️⃣ Commit
git commit -m "Your commit message"

## 5️⃣ See History
git log             # detailed log
git log --oneline   # compact log

## 6️⃣ Add Remote (when online)
git remote add origin git@github.com:USERNAME/REPO.git

## 7️⃣ Push to Remote
git push -u origin main   # first push
git push                  # later pushes

## 8️⃣ Pull Updates (when needed)
git pull

## 9️⃣ Undo / Go Back
git log
git checkout <commit_id>  # switch to old commit

## 📄 Example .gitignore
# OS files
.DS_Store
Thumbs.db

# Build files
*.o
*.out
*.exe

# IDE/editor files
.vscode/
*.swp

# Logs
*.log

# Other
node_modules/

✅ Commit offline → push when online → stay in control.
