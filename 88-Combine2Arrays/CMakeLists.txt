# CMakeList.txt: LeetCodeInterviewClassic150 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory ("26-RemoveTheRepeatedOnesInOrderedArray")
add_subdirectory ("27-RemoveElements")
add_subdirectory ("80-RemoveTheRepeatedOnesInOrderedArrayII")
add_subdirectory ("169-MajorityElements")
add_subdirectory ("189-CycledArray")

## 将源代码添加到此项目的可执行文件。
#add_executable (LeetCodeInterviewClassic150 
#"LeetCodeInterviewClassic150.cpp" 
#"LeetCodeInterviewClassic150.h"
#)

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET LeetCodeInterviewClassic150 PROPERTY CXX_STANDARD 20)
#endif()

# TODO: 如有需要，请添加测试并安装目标。
