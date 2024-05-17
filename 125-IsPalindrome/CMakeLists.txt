cmake_minimum_required (VERSION 3.8)

project ("125-IsPalindrome")

# 将源代码添加到此项目的可执行文件。
add_executable (125-IsPalindrome
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 125-IsPalindrome PROPERTY CXX_STANDARD 20)
endif()