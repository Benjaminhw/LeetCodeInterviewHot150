cmake_minimum_required (VERSION 3.8)

project ("136-OnlyShowOnceNumber")

# 将源代码添加到此项目的可执行文件。
add_executable (136-OnlyShowOnceNumber
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 136-OnlyShowOnceNumber PROPERTY CXX_STANDARD 20)
endif()