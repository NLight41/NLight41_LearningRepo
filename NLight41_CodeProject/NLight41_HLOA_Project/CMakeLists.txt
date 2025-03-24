<<<<<<< HEAD
cmake_minimum_required(VERSION 3.0)
project(NLight41)
=======
cmake_minimum_required(VERSION 3.10)
project(NLight41_HLOA_v0.1.0)

# 指定 C++ 標準
set(CMAKE_CXX_STANDARD 17)

# 加入 Eigen 和 CppAD
include_directories("c:/eigen-3.4.0")
include_directories("C:/CppAD-master/include")

# 設定可執行檔
add_executable(NLight41_HLOA_v0.1.0 main.cpp)
>>>>>>> fc875e787655ca96d4893bb635a82853a184033a
