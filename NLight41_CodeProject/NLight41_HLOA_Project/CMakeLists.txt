cmake_minimum_required(VERSION 3.10)
project(NLight41_HLOA)

# 指定 C++ 標準
set(CMAKE_CXX_STANDARD 17)

# 加入 Eigen 和 CppAD
find_package(EIGEN3 REQUIRED)
find_package(CppAD REQUIRED)

# 設定可執行檔
add_executable(NLight41_HLOA NLight41_HLOA_v0.1.0.cpp)
target_link_libraries(NLight41_HLOA Eigen3::Eigen CppAD::CppAD)

# 設定自動生成 CppAD 的 configure.hpp
configure_file(
C:/CppAD-master/include/cppad/configure.hpp.in
${CMAKE_BINARY_DIR}/include/cppad/configure.hpp
)
include_directories(${CMAKE_BINARY_DIR}/include)