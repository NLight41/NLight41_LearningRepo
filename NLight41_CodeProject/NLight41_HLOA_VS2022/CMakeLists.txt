# ============== MakeLists.txt ================
# [v0.2.1] - 03.27.2025 by NLight41

# 主要功能: 
# 1. 設定 CMake 版本、專案名稱與 C++ 標準
# 2. 設定與檢查函式庫 (Eigen、CppAD)，支援自動下載 (如果本機無法找到相對應的檔案)
# 3. 確保 `configure.hpp.in` 能成功轉換為 `configure.hpp` 
# 4. 設定編譯輸出目錄，確保 VS2022 找的到執行檔
# 5. 設定可執行檔，並正確連結至 目標函式庫(Library)


# 設定 CMake 最低版本 & 專案名稱
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
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


# 確保 `configure.hpp.in` 能成功轉換為 `configure.hpp`
set(CONFIGURE_HPP_IN "${CPPAD_INCLUDE_DIR}/cppad/configure.hpp.in")
set(CONFIGURE_HPP_OUT "${CMAKE_BINARY_DIR}/cppad/configure.hpp")

#確保輸出目錄存在
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/cppad/")

add_custom_command(
	OUTPUT ${CONFIGURE_HPP_OUT}
	COMMAND ${CMAKE_COMMAND} -E copy
		${CONFIGURE_HPP_IN}
		${CONFIGURE_HPP_OUT}
	DEPENDS ${CONFIGURE_HPP_IN}
	COMMENT "轉換 configure.hpp.in 為 configure.hpp"
)

# 確保 `configure.hpp` 轉換後才能執行編譯
add_custom_target(GenerateConfigHPP ALL DEPENDS ${CONFIGURE_HPP_OUT})

# 設定可執行檔，並確保 `configure.hpp` 運作成功
add_executable(NLight41_LearningRepo NLight41_HLOA_v0.1.1.cpp)
add_dependencies(NLight41_LearningRepo GenerateConfigHPP)

# 確保專案能找到 `configure.hpp`
include_directories(${CMAKE_BINARY_DIR}/cppad)