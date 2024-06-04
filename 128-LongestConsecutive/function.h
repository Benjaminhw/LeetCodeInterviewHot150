/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() == 1)
		{
			return 1;
		}
		else if (nums.size() == 0)
		{
			return 0;
		}
		sort(nums.begin(), nums.end());
		int ans = 1, i = 0, j = 1, minus = 0;
		while (i < nums.size() && j < nums.size())
		{
			while (j < nums.size() && (nums[j] == nums[j - 1] + 1 || nums[j] == nums[j - 1]))
			{
				if (nums[j] == nums[j - 1])
				{
					++minus;
				}
				else if (ans < j - i + 1 - minus)
				{
					ans = j - i + 1 - minus;
				}
				++j;
			}
			minus = 0;
			i = j;
			++j;
		}
		return ans;
	}
};