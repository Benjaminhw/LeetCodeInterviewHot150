/*
* ����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
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