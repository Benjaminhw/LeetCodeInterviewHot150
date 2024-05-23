cmake_minimum_required (VERSION 3.8)

project ("290-wordPattern")

# 将源代码添加到此项目的可执行文件。
add_executable (290-wordPattern
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 290-wordPattern PROPERTY CXX_STANDARD 20)
endif()