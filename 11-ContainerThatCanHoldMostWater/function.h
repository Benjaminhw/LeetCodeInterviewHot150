/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {
		int realHeight = 0;
		int result = 0;

		////exhaustive search 55/62
		//for (int j = 0; j < height.size(); ++j)
		//{
		//	for (int i = 0; i < j; ++i)
		//	{
		//		realHeight = min(height[i], height[j]);
		//		auto temp = abs(j - i) * realHeight;
		//		if (temp > result)
		//		{
		//			result = temp;
		//		}
		//	}
		//}

		if (height.size() == 2)
		{
			return min(height[1], height[0]);
		}
		if (height.size() == 1)
		{
			return 0;
		}

		//若向内移动短板，水槽的短板可能变大，因此下个水槽的面积可能增大。
		//若向内移动长板，水槽的短板不变或变小，因此下个水槽的面积一定变小。

		//two pointers? compare the height's increment and the width's decrease.
		//A left pointer and a right pointer.
		int leftPointer = 0, rightPointer = height.size()-1;
		while (leftPointer != rightPointer)
		{
			if (height[leftPointer] > height[rightPointer])
			{
				--rightPointer;
			}
			else
			{
				++leftPointer;
			}
			auto S = min(height[leftPointer], height[rightPointer]) * (rightPointer - leftPointer);
			if (S > result)
			{
				result = S;
			}
		}
		
		return result;
	}
};