cmake_minimum_required (VERSION 3.8)

project ("135-GivingAwayCandies")

# 将源代码添加到此项目的可执行文件。
add_executable (135-GivingAwayCandies
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 135-GivingAwayCandies PROPERTY CXX_STANDARD 20)
endif()