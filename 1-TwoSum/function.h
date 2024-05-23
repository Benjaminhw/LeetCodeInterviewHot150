#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool judge(pair<int, int> x, pair<int, int> y) {
		return x.second < y.second;
	};

	vector<int> twoSum(vector<int>& nums, int target) {
		/*unordered_map<int, int> hashMap;
		int z = 0;
		for (auto& x : nums)
		{
			hashMap[z] = x;
			++z;
		}
		sort(hashMap.begin(), hashMap.end(), judge);
		int i = 0, j = nums.size() - 1;
		while (i != j)
		{
			if ()
		}*/
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					return { i,j };
				}
			}
		}
		return {};
	}
};