/*
* 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
如果存在，返回 true ；否则，返回 false 。
*/
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int i = 0, j = 0;
		//the slippery window
		unordered_map<int, int> hashMap;
		while (j <= k && j < nums.size())
		{
			if (hashMap.find(nums[j]) == hashMap.end())
			{
				hashMap[nums[j]] = 1;
			}
			else
			{
				return true;
			}
			++j;
		}
		while (j < nums.size())
		{
			hashMap.erase(nums[i]);
			if (hashMap.find(nums[j]) == hashMap.end())
			{
				hashMap[nums[j]] = 1;
			}
			else
			{
				return true;
			}
			++i;
			++j;
		}
		return false;
	}
};