/*����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��

��Ŀ���� ��֤ ���� nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����  32 λ ������Χ�ڡ�

�� ��Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣*/


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
			//���ʲ���pre[0]��pos[n-1]�ģ�����Ҳ����Ҫ��������λ�õ�ֵ
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