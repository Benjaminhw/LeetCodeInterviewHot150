﻿cmake_minimum_required (VERSION 3.8)

project ("121-TheBestTimingToBuyStock")

# 将源代码添加到此项目的可执行文件。
add_executable (121-TheBestTimingToBuyStock
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 121-TheBestTimingToBuyStock PROPERTY CXX_STANDARD 20)
endif()