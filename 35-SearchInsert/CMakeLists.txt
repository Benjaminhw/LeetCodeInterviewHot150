cmake_minimum_required (VERSION 3.8)

project ("35-SearchInsert")

# 将源代码添加到此项目的可执行文件。
add_executable (35-SearchInsert
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 35-SearchInsert PROPERTY CXX_STANDARD 20)
endif()