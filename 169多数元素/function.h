#pragma once
/*����һ����СΪ n ������ nums ���������еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ��� ����  n/2  ��Ԫ�ء�

����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�*/

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
		//������Ȼ���С����������ͬ��Ԫ��
		tempTarget = nums[0];//��Ϊ��
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == tempTarget)
			{
				++tempCount;
			}
			if (nums[i] != tempTarget || i + 1 == nums.size())//���Ȼ����ǵ�β�͵����
			{
				if (tempCount > nums.size() / 2)//ע������Ǹ�����
				{
					count = tempCount;
					target = tempTarget;
				}
				tempCount = 1;//caution
				tempTarget = nums[i];
			}
		}
		return target;//�ٶ��������д����Ԫ��
	}
};

//�����ǹ�ϣ�� Why can't I figure it out.
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
//ͻȻ�뵽 Minority Report�����ɱ���