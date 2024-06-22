cmake_minimum_required (VERSION 3.8)

project ("ODInterview")

# 将源代码添加到此项目的可执行文件。
add_executable (ODInterview
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ODInterview PROPERTY CXX_STANDARD 20)
endif()