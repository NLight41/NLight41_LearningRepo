# Git 學習筆記  
> 此內容教學以 Windows系統 為主。  
  
> 建立時間 03.10.2025 by NLight41  
> [返回 NLight41 本站](https://nlight41.github.io/NLight41_LearningRepo/)    
  
---
  
## 如何開始你的 Git 第一步  
- [Git 官網下載](https://git-scm.com/downloads)  
  
1. 下載完後，右鍵開啟 CMD命令提示單元/PowerShell  
  
2. 輸入 `git --version` 測試是否安裝成功，此時通常會顯示git版本代表已成功安裝。  
  
---
  
## 如何利用 GitBash 將 GitHub倉庫 同步至本地  
1. 右鍵開啟 GitBash (如何快速開啟: 右鍵 -> 更多內容 -> Git Bash Here)  
  
2. 第一次使用請先設定自己的名稱與信箱，並使用`-l`或`--list`檢查是否設定成功。  
  
```bash
	git config --global user.name "使用者名稱"
	git config --global user.email "使用者信箱"
	git config --list
```
  
3. 將想要的GitHub倉庫連結 `clone` 至本機  
  
```bash
  git clone <倉庫HTTPS>
```

4. 進入該資料夾，即可完成設定。  
- **注意事項: `cd`後面的路徑必須使用`/`，而非Windows常用的`\`**  
- **更重要的是: 為了避免移動時發生錯誤，請儘量將路徑書寫完全，例如: `cd /c/user/name/桌面/repo`**  
- 小技巧: 可用指令`pwd`來查詢當前位置

```bash
  cd /~
```

