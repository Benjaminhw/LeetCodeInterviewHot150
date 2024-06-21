cmake_minimum_required (VERSION 3.8)

project ("236-lowestCommonAncestor")

# 将源代码添加到此项目的可执行文件。
add_executable (236-lowestCommonAncestor
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 236-lowestCommonAncestor PROPERTY CXX_STANDARD 20)
endif()