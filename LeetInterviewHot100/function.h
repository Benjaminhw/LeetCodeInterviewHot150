#pragma once
#include <iostream>
#include <vector>

class Solution {
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
	{
		int flag1 = 0, flag2 = 0;
		auto x = nums1;
		while (!(flag1 >= m && flag2 >= n)) //破烂题的判断写了一万年 这里的逻辑是每次循环加一个，并且上限是他们同时等于对应上限的时候
		{
			if (flag1 == m)
			{
				x[flag1 + flag2] = nums2[flag2];
				++flag2;
			}
			else if (flag2 == n)
			{
				x[flag1 + flag2] = nums1[flag1];
				++flag1;
			}
			else
			{
				if (nums1[flag1] <= nums2[flag2])
				{
					x[flag1 + flag2] = nums1[flag1];
					++flag1;
				}
				else
				{
					x[flag1 + flag2] = nums2[flag2];
					++flag2;
				}
			}
		}
		nums1 = x;
	}
};