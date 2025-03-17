# C++ 學習筆記  
> 建立時間 03.10.2025 by NLight41  
  
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
---

# 02-ControlFlow  
## 控制流程-if/else  
  
```cpp

```
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
  
---

## 04-DataStructures  
- 資料結構  
