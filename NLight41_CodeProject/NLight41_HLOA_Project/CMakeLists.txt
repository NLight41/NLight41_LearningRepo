cmake_minimum_required(VERSION 3.10)
project(NLight41_HLOA)

# 指定 C++ 標準
set(CMAKE_CXX_STANDARD 17)

# 加入 Eigen 和 CppAD
set(EIGEN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/toolbox/eigen-3.4.0/Eigen")
set(CPPAD_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/toolbox/CppAD-master/include/cppad")
include_directories(${EIGEN_INCLUDE_DIR} ${CPPAD_INCLUDE_DIR})


# 設定可執行檔
add_executable(NLight41_HLOA NLight41_HLOA_v0.1.1.cpp)
