# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCodeInterviewClassic150")

# 包含子项目。
add_subdirectory ("26-RemoveTheRepeatedOnesInOrderedArray")
add_subdirectory ("80-RemoveTheRepeatedOnesInOrderedArrayII")
add_subdirectory ("169-MajorityElements")
add_subdirectory ("189-CycledArray")
add_subdirectory ("27-RemoveElements")
add_subdirectory ("88-Combine2Arrays")