﻿# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.12)

project ("LeetCodeInterviewClassic150")

# 包含子项目 CodeToTests
# add_subdirectory ("CodeToTests")
add_subdirectory ("26-RemoveTheRepeatedOnesInOrderedArray")
add_subdirectory ("80-RemoveTheRepeatedOnesInOrderedArrayII")
add_subdirectory ("169-MajorityElements")
add_subdirectory ("189-CycledArray")
add_subdirectory ("27-RemoveElements")
add_subdirectory ("88-Combine2Arrays")
add_subdirectory ("121-TheBestTimingToBuyStock")
add_subdirectory ("122-TheBestTimingToBuyStockII")
add_subdirectory ("55-JumpGame")
add_subdirectory ("45-JumpGameII")
add_subdirectory ("274-H-Index")
add_subdirectory ("380-O1InsertDeleteGetRandomElement")
add_subdirectory ("238-ProductExceptItself")
add_subdirectory ("150-GasStation")
add_subdirectory ("135-GivingAwayCandies")
add_subdirectory ("42-CatchTheRain")
add_subdirectory ("13-RomanCharactorToInt")
add_subdirectory ("12-IntToRomanCharacter")
add_subdirectory ("58-LengthOfTheLastWord")
add_subdirectory ("14-TheLongestPrefix")
add_subdirectory ("151-ReverseTheSequenceOfWords")
add_subdirectory ("6-Z-ShapeTransform")
add_subdirectory ("28-FindTheFirstCompareInString")
add_subdirectory ("68-WordsAlignment")


# set(CMAKE_TOOLCHAIN_FILE "${sourceDir}/../vcpkg/scripts/buildsystems/vcpkg.cmake")

# find_package(fmt CONFIG REQUIRED)
# target_link_libraries(LeetCodeInterviewClassic150 PRIVATE fmt::fmt)