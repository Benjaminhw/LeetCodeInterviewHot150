cmake_minimum_required (VERSION 3.8)

project ("224-BasicCalculator")

# 将源代码添加到此项目的可执行文件。
add_executable (224-BasicCalculator
"function.h"
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 224-BasicCalculator PROPERTY CXX_STANDARD 20)
endif()