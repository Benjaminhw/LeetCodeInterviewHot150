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
add_subdirectory ("134-GasStation")
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
add_subdirectory ("125-IsPalindrome")
add_subdirectory ("392-IsSubsequence")
add_subdirectory ("167-TwoSum")
add_subdirectory ("11-ContainerThatCanHoldMostWater")
add_subdirectory ("15-ThreeSum")
add_subdirectory ("209-minSubArrayLen")
add_subdirectory ("3-lengthOfLongestNoRepeatSubstring")
add_subdirectory ("383-CanConstruct")
add_subdirectory ("30-connectAllTheSubstring")
add_subdirectory ("205-isIsomorphic")
add_subdirectory ("290-wordPattern")
add_subdirectory ("242-isAnagram")
add_subdirectory ("1-TwoSum")
add_subdirectory ("202-HappyNumber")
add_subdirectory ("219-ContainsNearbyDuplicate")
add_subdirectory ("228-SummaryRanges")
add_subdirectory ("20-IsValidBracket")
add_subdirectory ("104-BinaryTreeMaxDepth")
add_subdirectory ("100-SameTree")
add_subdirectory ("226-InvertTree")
add_subdirectory ("101-SymmetricTree")
add_subdirectory ("112-HasPathSum")
add_subdirectory ("222-CountCompleteBinaryTreeNodes")
add_subdirectory ("108-SortedArray2BST")
add_subdirectory ("35-SearchInsert")
add_subdirectory ("67-BinarySum")
add_subdirectory ("191-HammingWeight")
add_subdirectory ("136-OnlyShowOnceNumber")
add_subdirectory ("141-IfListHasCycle")
add_subdirectory ("21-MergeTwoLists")
add_subdirectory ("9-isPalindrome")
add_subdirectory ("66-PlusOne")
add_subdirectory ("637-BinaryTreeAverageOfLevels")
add_subdirectory ("530-MinimumDifference")
add_subdirectory ("190-ReverseBits")
add_subdirectory ("2-AddTwoNumbers")
add_subdirectory ("70-ClimbStairs")
add_subdirectory ("76-MinCoverSubString")
add_subdirectory ("36-isValidSudoku")
add_subdirectory ("54-SpiralOrder")
add_subdirectory ("73-SetZeros")
add_subdirectory ("48-Rotate90degree")
add_subdirectory ("287-GameOfLife")
add_subdirectory ("49-GroupAnagrams")
add_subdirectory ("128-LongestConsecutive")
add_subdirectory ("56-MergeTheInterval")
add_subdirectory ("57-InsertIntervals")
add_subdirectory ("452-UseLeastArrowToShootBalloons")
add_subdirectory ("71-SimplifyPath")
add_subdirectory ("155-MinStack")
add_subdirectory ("150-EvalRPN")
add_subdirectory ("98-IsValidBST")
add_subdirectory ("224-BasicCalculator")
add_subdirectory ("138-CopyRandomList")
add_subdirectory ("92-ReverseBetween")
add_subdirectory ("61-RotateRight")
add_subdirectory ("86-PartitionOfList")
add_subdirectory ("82-deleteDuplicatesList")
add_subdirectory ("105-BuilTreeInPreAndMidOrder")
add_subdirectory ("25-ReverseKGroup")
add_subdirectory ("19-RemoveNthFromEnd")
add_subdirectory ("146-LRUCache")
add_subdirectory ("114-BinaryTree2List")
add_subdirectory ("124-MaxPathSum")
add_subdirectory ("117-FillTheRightNodePointer")
add_subdirectory ("173-BSTIterator")
add_subdirectory ("236-lowestCommonAncestor")
add_subdirectory ("199-BinaryTreeRightSideView")
add_subdirectory ("102-LevelOrder")
add_subdirectory ("103-ZigzagLevelOrder")
add_subdirectory ("230-KthSmallest")
add_subdirectory ("200-NumOfIslands")
add_subdirectory ("215-FindKthLargest")
add_subdirectory ("502-IPOFindMaximizedCapital")
add_subdirectory ("130-AreaSurrounded")
add_subdirectory ("133-CloneGraph")
add_subdirectory ("1056-ConfusingNumber")
add_subdirectory ("1427-MoveTheStrings")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")
#add_subdirectory ("")

# set(CMAKE_TOOLCHAIN_FILE "${sourceDir}/../vcpkg/scripts/buildsystems/vcpkg.cmake")

# find_package(fmt CONFIG REQUIRED)
# target_link_libraries(LeetCodeInterviewClassic150 PRIVATE fmt::fmt)