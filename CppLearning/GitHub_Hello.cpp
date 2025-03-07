#include <iostream>

int main(){
	std::cout << "Hello, GitHub! This is my first C++ project." << std::endl;
	return 0;
} 
// 初次嘗試使用"std::"前綴，而非使用平常使用的"using namespace std;"
// "std::"前綴主要用來引用C++標準函式庫中的成員，例如 cout、cin、endl、vector、string 等
// 使用"std::"前綴的好處：
// 可確保標準函式庫名稱(namespace std)不與使用者命名自定義的名稱衝突
// 也可單獨針對特定物件使用using，例如 "using std::cout;"、"using std::endl;" 等