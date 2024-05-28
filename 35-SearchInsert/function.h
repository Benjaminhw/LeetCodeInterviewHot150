/*
* 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int a = 0, b = nums.size() - 1;
		while (a < b)
		{
			if (target > nums[(a + b) / 2])
			{
				a = (a + b) / 2 + 1;
			}
			else if (target == nums[(a + b) / 2])
			{
				return (a + b) / 2;
			}
			else
			{
				b = (a + b) / 2 - 1;
			}
		}
		if (target <= nums[a])
		{
			return a;
		}
		else
		{
			return a + 1;
		}
		return target;
	}
};