/*
* ����һ��  ���ظ�Ԫ�� �� ���� �������� nums ��

���� ǡ�ø����������������� �� ��С���� ���䷶Χ�б� ��Ҳ����˵��nums ��ÿ��Ԫ�ض�ǡ�ñ�ĳ�����䷶Χ�����ǣ�
���Ҳ���������ĳ����Χ�������� nums ������ x ��

�б��е�ÿ�����䷶Χ [a,b] Ӧ�ð����¸�ʽ�����

"a->b" ����� a != b
"a" ����� a == b
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> tempStrings;
		if (nums.size() == 1)
		{
			//if the size is one
			tempStrings.push_back(to_string(nums[0]));
			return tempStrings;
		}
		else if (nums.size() == 0)
		{
			return tempStrings;
		}
		bool isGoingUp;
		if (nums[1] > nums[0])
		{
			isGoingUp = true;
		}
		else
		{
			isGoingUp = false;
		}
		int i = 0, j = 0;
		while (i < nums.size())
		{
			j = i;
			while (j + 1 < nums.size() && nums[j + 1] == nums[j] + isGoingUp*1)
			{
				++j;
			}
			if (j == i)
			{
				tempStrings.push_back(to_string(nums[i]));
			}
			else
			{
				tempStrings.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
			}
			i=j+1;
		}
		return tempStrings;
	}
};