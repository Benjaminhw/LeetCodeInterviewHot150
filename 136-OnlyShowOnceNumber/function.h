/*����һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨����������⣬�Ҹ��㷨ֻʹ�ó�������ռ䡣
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		if (nums.size() == 1)
		{
			return nums[0];
		}
		result = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			result ^= nums[i];
		}
		return result;
	}
};