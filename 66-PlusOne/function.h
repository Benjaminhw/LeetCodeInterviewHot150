/*给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

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