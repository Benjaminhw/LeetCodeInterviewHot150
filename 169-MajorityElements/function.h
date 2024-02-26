#pragma once
/*给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于  n/2  的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int target = 0, tempTarget, count = 0, tempCount = 0, size = nums.size();
		sort(nums.begin(), nums.end());
		//先排序，然后从小到大来找相同的元素
		tempTarget = nums[0];//不为空
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == tempTarget)
			{
				++tempCount;
			}
			if (nums[i] != tempTarget || i + 1 == nums.size())//不等或者是到尾巴的情况
			{
				if (tempCount > nums.size() / 2)//注意可能是浮点数
				{
					count = tempCount;
					target = tempTarget;
				}
				tempCount = 1;//caution
				tempTarget = nums[i];
			}
		}
		return target;//假定了总是有大多数元素
	}
};

//最快的是哈希表 Why can't I figure it out.
class SolutionTop {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> counts;
		int majority = 0, cnt = 0;
		for (int num : nums) {
			++counts[num];
			if (counts[num] > cnt) {
				majority = num;
				cnt = counts[num];
			}
		}
		return majority;
	}
};
//突然想到 Minority Report少数派报告