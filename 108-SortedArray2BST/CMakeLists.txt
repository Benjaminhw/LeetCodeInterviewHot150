cmake_minimum_required (VERSION 3.8)

project ("108-SortedArray2BST")

# 将源代码添加到此项目的可执行文件。
add_executable (108-SortedArray2BST
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 108-SortedArray2BST PROPERTY CXX_STANDARD 20)
endif()