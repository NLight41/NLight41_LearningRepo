# ============== MakeLists.txt ================
# [v0.2.0] - 03.27.2025 by NLight41

# 本 CMake 設定檔的主要功能: 
# 1. 設定 CMake 版本、專案名稱與 C++ 標準。
# 2. 設定與檢查函式庫 (Eigen、CppAD)，支援自動下載 (如果本機無法找到相對應的檔案)。
# 3. 設定編譯輸出目錄，確保 VS2022 找的到執行檔。
# 4. 設定可執行檔，並正確連結至 目標函式庫(Library) 及 標頭檔(include)。


# 設定 CMake 最低版本 及 專案名稱
cmake_minimum_required(VERSION 3.16)
project(NLight41_LearningRepo)

# 設定 C++17 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ============ 第三方函式庫設定 ===============

# 預設本機函式庫路徑
set(EIGEN_INCLUDE_DIR "C:/toolbox/eigen-3.4.0")
set(CPPAD_INCLUDE_DIR "C:/toolbox/CppAD-master/include")

# 自動檢查本機是否已有 Eigen，如果沒有則自動下載 
if(NOT EXISTS ${EIGEN_INCLUDE_DIR})
	message(STATUS "未找到 Eigen 函式庫，將自動下載 Eigen 3.4.0")
	include(FetchContent)
	FetchContent_Declare(
		eigen
		GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
		GIT_TAG 3.4.0
	)
	FetchContent_MakeAvailable(eigen)
	set(EIGEN_INCLUDE_DIR ${eigen_SOURCE_DIR})
endif()

# 自動檢查本機是否已有 CppAD，如果沒有則自動下載 
if(NOT EXISTS ${CPPAD_INCLUDE_DIR})
	message(STATUS "未找到 CppAD 函式庫，將自動下載最新版本")
	include(FetchContent)
	FetchContent_Declare(
		cppad
		GIT_REPOSITORY https://github.com/coin-or/CppAD.git
		GIT_TAG master
	)
	FetchContent_MakeAvailable(cppad)
	set(CPPAD_INCLUDE_DIR ${cppad_SOURCE_DIR}/include)
endif()

# 將函式庫 include 目錄加到專案
include_directories(${EIGEN_INCLUDE_DIR} ${CPPAD_INCLUDE_DIR})


# ================ 編譯設定 ===================

# 設定輸出目錄，確保 VS2022 不會找不到執行檔
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# 確保 `configure.hpp.in` 能成功轉換為 `configure.hpp`
configure_file(
	${CMAKE_SOURCE_DIR}/cppad/configure.hpp.in
	${CMAKE_BINARY_DIR}/cppad/configure.hpp 
	@only
)
include_directories(${CMAKE_BINARY_DIR})

# 設定可執行檔
add_executable(NLight41_LearningRepo NLight41_HLOA_v0.1.1.cpp)