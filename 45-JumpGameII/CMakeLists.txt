﻿cmake_minimum_required (VERSION 3.8)

project ("45-JumpGameII")

# 将源代码添加到此项目的可执行文件。
add_executable (45-JumpGameII
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 45-JumpGameII PROPERTY CXX_STANDARD 20)
endif()