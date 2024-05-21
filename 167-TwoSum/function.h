/*给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {

		//int index1 = 0, index2 = numbers.size()-1;
		//int tempSum = 0;

		////before cut the branch: 19/23

		//for (; index2 < numbers.size(); ++index2)
		//{
		//	for (index1 = 0; index1 < index2; ++index1)
		//	{
		//		tempSum = numbers[index1] + numbers[index2];
		//		if (tempSum == target)
		//		{
		//			return { index1 + 1,index2 + 1 };
		//		}
		//	}
		//}

		//tempSum = numbers[index1] + numbers[index2];
		//if (tempSum == target)
		//{
		//	return { index1 + 1,index2 + 1 };
		//}

		//// two pointers 13/25 有一个问题是如果 两次小的增量加起来大于某单次增量，那么就错过了中间这个值
		//// 2024-05-21 3PM BenjaminH @MZ Tech
		//while (index1 < index2 && index2 < numbers.size())
		//{
		//	if (index1 + 1 == index2)
		//	{
		//		++index2;
		//	}
		//	else if (index2 + 1 >= numbers.size())
		//	{
		//		++index1;
		//	}
		//	else if (numbers[index1 + 1] - numbers[index1] <= numbers[index2 + 1] - numbers[index2])
		//	{
		//		++index1;
		//	}
		//	else if (index2 + 1 < numbers.size())
		//	{
		//		++index2;
		//	}
		//	tempSum = numbers[index1] + numbers[index2];
		//	if (tempSum == target)
		//	{
		//		return { index1 + 1,index2 + 1 };
		//	}
		//}

		//This is the right 2-pointers-way
		int index1 = 0, index2 = numbers.size() - 1;
		int tempSum = 0;
		while (index1 != index2)
		{
			if (numbers[index1] + numbers[index2] == target)
			{
				return { index1 + 1,index2 + 1 };
			}
			else if (numbers[index1] + numbers[index2] > target)
			{
				--index2;
			}
			else
			{
				++index1;
			}
		}

		cout << "Wrong Answer";
		return { index1 ,index2 };
	}
};