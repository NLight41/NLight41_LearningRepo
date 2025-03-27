cmake_minimum_required(VERSION 3.16)
project(NLight41_LearningRepo)

# 設定 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 讓 CMake 使用本機已有的函式庫
set(EIGEN_INCLUDE_DIR "C:/toolbox/eigen-3.4.0")
set(CPPAD_INCLUDE_DIR "C:/toolbox/CppAD-master/include")

# 讓 CMake 直接包含這些函式庫
include_directories(${EIGEN_INCLUDE_DIR} ${CPPAD_INCLUDE_DIR})

# 設定輸出目錄，確保 VS2022 不會找不到執行檔
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 設定可執行檔
add_executable(NLight41_LearningRepo NLight41_HLOA_v0.1.1.cpp)
