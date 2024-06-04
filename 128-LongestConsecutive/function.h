/*
����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�

������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
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