#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*����һ������Ϊ n �� 0 ������������ nums����ʼλ��Ϊ nums[0]��

ÿ��Ԫ�� nums[i] ��ʾ������ i ��ǰ��ת����󳤶ȡ����仰˵��������� nums[i] �����������ת������ nums[i + j] ��:

0 <= j <= nums[i] 
i + j < n
���ص��� nums[n - 1] ����С��Ծ���������ɵĲ����������Ե��� nums[n - 1]�� */

class Solution {
public:
    int jump(vector<int>& nums) {
		int maxJumpLength = 0,realMaxLength=0,minJumpStep=0;//�����Ծ����
		for (int i = 0; i < nums.size()/*-1����Ϊ���������һ���Ķ���true*/; ++i)
		{

			if (nums[i] != 0) //��¼��������Զ�ľ���
			{
				if (nums[i] > maxJumpLength)
				{
					if (maxJumpLength <= 0)
					{

					}
					++minJumpStep;
					
					maxJumpLength = nums[i];
					//j = i;//j��ָ��
				}
				if (i + maxJumpLength >= nums.size() - 1)
				{
					return minJumpStep;
				}
			}
			--maxJumpLength;//ÿ�ƶ�һ��jumpLength���� �����ǲ���0 jumplength���ü���
		}
		return minJumpStep;
    }
};