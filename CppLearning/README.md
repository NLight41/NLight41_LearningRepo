# C++ 學習筆記  
> 建立時間 03.10.2025 by NLight41  
> [返回 NLight41 本站](https://nlight41.github.io/NLight41_LearningRepo/)  
  
---
  
### 為什麼我想學 C++ ?  
> **C++ 是一門高效能語言，適合系統開發與運算。與 Python 相比雖然學習難度增加了不少，但我認為也更接近基礎。**
  
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
  
### 在使用 if/else 前，我認為該優先思考的一些項目：  
  
1. 條件導向思考：  
在撰寫 if/else 前，先釐清所有可能的條件範圍與分類對應的行為,可幫助避免重複條件、遺漏邏輯，使判斷邏輯更完整，結構更穩定。  
2. 最小決策單位：  
每個 if/else 僅處理一項單一邏輯，避免多層巢狀與複合條件,提升可讀性，便於除錯與維護，並減少誤解或錯誤。  
3. 避免旗標變數：  
避免多餘的 bool 旗標搭配後續判斷，應直接採用 return / break 等控制流,可精簡程式碼結構、減少變數依賴，提升邏輯清晰度與直觀性。  
  
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