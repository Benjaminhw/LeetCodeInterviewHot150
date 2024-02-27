#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*����һ���Ǹ��������� nums �������λ������� ��һ���±� �������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

�ж����Ƿ��ܹ��������һ���±꣬������ԣ����� true �����򣬷��� false �� */

//��ϸһ����ֻҪû��0�϶���������β~~��Ȼ��һ��λ�ú�����ŵ�0С�����������Ҳ�ǿ��Եġ�

class SolutionA {
public:
	bool canJump(vector<int>& nums) {
		int totalLength = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int max = 0;
			int tempi = 0;
			for (int j = 1; j <= nums[i] && j + i < nums.size(); ++j)
			{
				if (j + nums[j + i] > max)
				{
					max = j + nums[j + i];//�������ļ�����Ա��´�ѡ��
					tempi = i + j;
				}
			}
			totalLength += max;
			if (max <= nums[i] || nums[i] == 0)
			{//�������˾�ֹͣ
				break;
			}
			i = tempi;
		}
		if (totalLength >= nums.size() || nums.size() == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Solution {
public:
	bool canJump(vector<int>& nums) {
		//��˫ָ����0�ĸ���
		int zeroCount = 0;
		int j = 0;
		int maxJumpLength = 0;//�����Ծ����
		for (int i = 0; i < nums.size() - 1/*-1����Ϊ���������һ���Ķ���true*/; ++i)
		{
			--maxJumpLength;//ÿ�ƶ�һ��jumpLength���� �����ǲ���0 jumplength���ü���
			if (nums[i] != 0) //��¼��������Զ�ľ���
			{
				zeroCount = 0;
				if (nums[i] > maxJumpLength)
				{
					maxJumpLength = nums[i];
					j = i;//j��ָ��
				}
			}
			else
			{
				++zeroCount;
				if (maxJumpLength <= zeroCount)
				{
					return false;
				}
			}
		}
		return true;
	}
};