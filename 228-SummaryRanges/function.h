/*
* 给定一个  无重复元素 的 有序 整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，
并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> tempStrings;
		if (nums.size() == 1)
		{
			//if the size is one
			tempStrings.push_back(to_string(nums[0]));
			return tempStrings;
		}
		else if (nums.size() == 0)
		{
			return tempStrings;
		}
		bool isGoingUp;
		if (nums[1] > nums[0])
		{
			isGoingUp = true;
		}
		else
		{
			isGoingUp = false;
		}
		int i = 0, j = 0;
		while (i < nums.size())
		{
			j = i;
			while (j + 1 < nums.size() && nums[j + 1] == nums[j] + isGoingUp*1)
			{
				++j;
			}
			if (j == i)
			{
				tempStrings.push_back(to_string(nums[i]));
			}
			else
			{
				tempStrings.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
			}
			i=j+1;
		}
		return tempStrings;
	}
};