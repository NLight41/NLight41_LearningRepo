# C++ 學習筆記  
> 建立時間 03.10.2025 by NLight41  
> [返回 NLight41 本站](https://nlight41.github.io/NLight41_LearningRepo/)  
  
---
  
### 為什麼我想學 C++ ?  
> **C++ 是一門高效能語言，適合系統開發與運算。與 Python 相比雖然學習難度增加了不少，但我認為也更接近基礎。**
  
本教學範例極主觀，請酌量參閱。  
下列將列出此頁面的主要目錄：  

    1. 基礎語法
      1.1 宣告變數及型別
      1.2 輸入輸出
      1.3 運算子運用
    2. 控制流程
      2.1 if/else 基礎語法
      2.2 那些學校通常不會教的 - 對於禁止使用 if/else 的情況
      2.3 for 迴圈基礎
    3. 函式運用
    4. 資料結構
```
壹、基礎語法
  1. 變數與型別
    int, double, char, bool, string, auto,型別轉換、記憶體配置、數值精度處理
  2. 常數與巨集
    const, constexpr, #define,巨集定義 vs 常數安全性、編譯期常數
  3. 運算子
    算術：+ - * / %  邏輯：`&&,
  4. 輸入輸出 I/O
    cin, cout, getline, printf, scanf,字串處理、多行輸入、格式化輸出
  5. 註解與命名規範
    //, /* */，駝峰式、底線命名,良好風格建立、易讀性維護
  6. 主程式結構
    main(), return, 編譯鏈,C++ 程式執行流程與錯誤碼結構
  7. 命名空間
    using namespace std;, std::,命名衝突處理、命名空間隔離設計

貳、控制流程
  1. 條件判斷,
    if / else if / else, switch-case, ?: 三元運算,最小決策單位設計、條件導向邏輯
  2. 迴圈結構,
    for, while, do while,範圍設計、計數器控制、巢狀迴圈最佳化
  3. 流程控制語句,
    break, continue, return, exit(),提早中斷、跳出邏輯、early return 最佳實踐
  4. 錯誤處理機制,
    try-catch, throw, assert,例外安全、除錯技巧、邏輯斷言設計
  5. 旗標變數的取代設計,
    return、函式結構優化,精簡流程、提高邏輯清晰度
```

---
# 01-Basics  
## 基礎語法1-宣告變數與型別  
C++ 是一門"靜態弱型別"的語言，使用變數前我們應該先 **宣告型別**  
基本格式:  `變數型別 變數名稱 (=變數內容);`  
  
```cpp
  int a = 10; //整數
  double b = 3.14; //浮點數
  char c = 'A'; //字元
  std::string d = "Hello"; //字串
  bool e = ture; //布林值
```
  
## 基礎語法2-輸入輸出  
C++ 通常輸入輸出以 `cin`,`cout` 為主。
比較需要注意的是: 
如果前面沒有使用`using`來宣告命名空間，在使用std的函式時，我們必須加上`std::`前綴來讓編譯器知道我們要幹嘛。
  
```cpp
  int x, y;
  std::cin >> x >> y;
  std::cout << x << y << std::endl;
```
  
## 基礎語法3-運算子運用  
```cpp
  /* 未來更新 */ 
```
---

# 02-ControlFlow  
## 控制流程-if/else  
  
### 一、撰寫前的思路調整：  
在使用 if/else 前，我認為該優先思考的一些項目：  
  
> 1. 條件導向思考：  
> 在撰寫 if/else 前，先釐清所有可能的條件範圍與分類對應的行為,可幫助避免重複條件、遺漏邏輯，使判斷邏輯更完整，結構更穩定。  
> 2. 最小決策單位：  
> 每個 if/else 僅處理一項單一邏輯，避免多層巢狀與複合條件,提升可讀性，便於除錯與維護，並減少誤解或錯誤。  
> 3. 避免旗標變數：  
> 避免多餘的 bool 旗標搭配後續判斷，應直接採用 return / break 等控制流,可精簡程式碼結構、減少變數依賴，提升邏輯清晰度與直觀性。  
  
- 其中，我主要會推薦以這兩個基本的架構來撰寫  
  
1. 以傳統 if/else 結構來撰寫：  
```cpp
if (score >= 90) {
    cout << "A";
} else {
    if (score >= 80) {
        cout << "B";
    } else {
        if (score >= 70) {
            cout << "C";
        } else {
            cout << "D";
        }
    }
}
```

  
2. 若改為以 else if 結構撰寫？  
```cpp
if (score >= 90) {
    cout << "A";
} else if (score >= 80) {
    cout << "B";
} else if (score >= 70) {
    cout << "C";
} else {
    cout << "D";
}
```
➡️ 可以發現，加入 else if 函式的架構來撰寫，我認為是比傳統寫法更加清晰的。  

---

# 03-Functions  
## 函式-引入函式庫及命名空間  
我們以`#include`來引入一個函式庫，而`<iostream>`就是一個包含輸入輸出的標準函式庫。  
`using`用來宣告要使用的命名空間，基本上都是使用 標準函式庫std 居多，  
但也其實可以單獨宣告想用的函式，例如`using std::cin;`等等。  
  
```cpp
  #include <iostream>
  using namespace std;
```
  
也可以使用競賽用的函式庫 `<bits/stdc++.h>` 它整合了平常使用的 std 與其他常見的函式庫。  
  
```cpp
  #include <bits/stdc++.h>
```
  
---

## 04-DataStructures  
- 資料結構  


```cpp
  /* 未來更新 */ 
```
---
> [返回網頁目錄](https://nlight41.github.io/NLight41_LearningRepo/WebStorage/)  