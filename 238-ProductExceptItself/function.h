/*给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。*/


#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> pre = nums;
		vector<int> pos = nums;
		int initial = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			//访问不到pre[0]和pos[n-1]的，所以也不需要管这两个位置的值
			initial *= nums[i-1];
			pre[i] = initial;
		}
		initial = 1;
		for (int i=nums.size()-2; i>=0; --i)
		{
			initial *= nums[i + 1];
			pos[i] = initial;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i == 0)
			{
				nums[i] = pos[i];
			}
			else if (i == nums.size() - 1)
			{
				nums[i] = pre[i];
			}
			else
			{
				nums[i] = pre[i] * pos[i];
			}
		}
		return nums;
	}
};