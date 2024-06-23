cmake_minimum_required (VERSION 3.8)

project ("130-AreaSurrounded")

# 将源代码添加到此项目的可执行文件。
add_executable (130-AreaSurrounded
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 130-AreaSurrounded PROPERTY CXX_STANDARD 20)
endif()