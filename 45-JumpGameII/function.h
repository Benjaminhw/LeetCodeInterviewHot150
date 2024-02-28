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
		if (nums.size() == 1)
		{
			return 0;
		}
		//the boundary condition near the tail is relatively important. 
		int maxJumpLength = 0, realMaxJumpLength = 0, minJumpStep = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			//No need to consider zero now
			if (nums[i] > maxJumpLength)
			{
				maxJumpLength = nums[i];
				//j = i;//slower pointer j

			}
			//always calculate the real max jump length
			if (realMaxJumpLength <= 0)
			{
				realMaxJumpLength = maxJumpLength;
				++minJumpStep;
			}
			//here use the real maxjumplength 
			if (i + realMaxJumpLength >= nums.size() - 1)
			{
				//realMaxJumpLength indicates the actual
				//++minJumpStep;
				return minJumpStep;
			}
			--maxJumpLength;//Every step JumpLength will be shorter.
			--realMaxJumpLength;
		}
		return minJumpStep;
	}
};