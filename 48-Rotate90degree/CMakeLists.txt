cmake_minimum_required (VERSION 3.8)

project ("48-Rotate90degree")

# 将源代码添加到此项目的可执行文件。
add_executable (48-Rotate90degree
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 48-Rotate90degree PROPERTY CXX_STANDARD 20)
endif()