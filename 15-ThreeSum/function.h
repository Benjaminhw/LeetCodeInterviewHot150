/*
* 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//as it already says it's about double pointer.
		//There seems to be a problem about fetch combinations
		//beautiful three layers round
		vector<vector<int>> results;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > 0 && nums[i - 1] == nums[i])
			{
				continue;
			}
			int j = i + 1, k = nums.size() - 1;

			//double pointers
			while (j < k && j < nums.size() && k>0)
			{
				auto temp = nums[i] + nums[j] + nums[k];
				if (temp == 0)
				{
					vector<int> x = { nums[i],nums[j],nums[k] };
					results.push_back(x);
					do {
						++j;
					} while (j <= k && j < nums.size() && nums[j] == nums[j - 1]);
				}
				else if (temp > 0)
				{
					do {
						--k;
					} while (j <= k && k > 0 && nums[k] == nums[k + 1]);
				}
				else//temp <0
				{
					do {
						++j;
					} while (j <= k && j < nums.size() && nums[j] == nums[j - 1]);
				}

			}

			////normal exhaustive search-308/313 Still have to use double pointers.
			//for (int j = i + 1; j < nums.size(); ++j)
			//{
			//	if (j > i + 1 && nums[j - 1] == nums[j])
			//	{
			//		continue;
			//	}
			//	for (int k = j + 1; k < nums.size(); ++k)
			//	{
			//		if (k > j + 1 && nums[k - 1] == nums[k])
			//		{
			//			continue;
			//		}
			//		if (nums[i] + nums[j] + nums[k] == 0)
			//		{
			//			//needs deduplication
			//			vector<int> x = { nums[i],nums[j],nums[k] };
			//			//sort(x.begin(), x.end());
			//			results.push_back(x);
			//			break;
			//		}
			//	}
			//}
		}
		////deduplication here at first
		//sort(results.begin(), results.end());
		//results.erase(unique(results.begin(), results.end()), results.end());
		return results;
	}
};