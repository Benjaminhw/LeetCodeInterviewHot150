cmake_minimum_required (VERSION 3.8)

project ("28-FindTheFirstCompareInString")

# 将源代码添加到此项目的可执行文件。
add_executable (28-FindTheFirstCompareInString
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 28-FindTheFirstCompareInString PROPERTY CXX_STANDARD 20)
endif()