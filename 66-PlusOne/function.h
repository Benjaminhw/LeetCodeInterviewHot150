/*����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

*/

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {

		////66%
		//string digitss;
		//for (auto x : digits)
		//{
		//	digitss +=to_string(x);
		//}
		//long long digitsi = atoll(digitss.c_str())+1;
		//vector<int> digitsr;
		//digitss = to_string(digitsi);
		//for (auto x : digitss)
		//{
		//	string y;
		//	y += x;
		//	digitsr.emplace_back(atoi(y.c_str()));
		//}
		//return digitsr;
		
		if (digits.empty())
		{
			return { 1 };
		}

		bool isUpgrade = false, lastFlag = true;

		for (int i = digits.size() - 1; i >= 0; --i)
		{
			if (lastFlag )
			{
				lastFlag = false;
				if (digits[i] == 9)
				{
					isUpgrade = true;
					digits[i] = 0;
				}
				else
				{
					isUpgrade = false;
					digits[i] += 1;
					return digits;
				}
			}
			else
			{
				if (isUpgrade)
				{
					if (digits[i] == 9)
					{
						digits[i] = 0;
					}
					else
					{
						digits[i] += 1;
						isUpgrade = false;
					}
				}
				else
				{
					return digits;
				}
			}
		}

		if (isUpgrade)
		{
			digits.insert(digits.begin(),1);
		}
		return digits;
	}
};