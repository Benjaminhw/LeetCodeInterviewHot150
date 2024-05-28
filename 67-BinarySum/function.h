/*
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
*/

#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;


class Solution {
public:
	string addBinary(string a, string b) {
		int i = 0;
		bool isUpgrade = false;
		stack<char> tempStack;
		string result;

		//fill blanks with zero
		int fill = abs((int)(a.size() - b.size()));
		if (a.size() > b.size())
		{
			for (int j = 0; j < fill; ++j)
			{
				b.insert(0, "0");
			}
		}
		else
		{
			for (int j = 0; j < fill; ++j)
			{
				a.insert(0, "0");
			}
		}
		int max = a.size() - 1;

		while (i < a.size())
		{

			if (a[max - i] == b[max - i])
			{
				//judge if there is carry.
				if (isUpgrade)
				{
					tempStack.push('1');
				}
				else
				{
					tempStack.push('0');
				}
				//stack operations
				if (a[max - i] == '1')
				{
					isUpgrade = true;
				}
				else if (a[max - i] == '0')
				{
					isUpgrade = false;
				}
			}
			else
			{
				//
				if (isUpgrade)
				{
					isUpgrade = true;
					tempStack.push('0');
				}
				else
				{
					isUpgrade = false;
					tempStack.push('1');
				}
			}
			++i;
		}
		//output
		if (isUpgrade)
		{
			result = "1";
		}
		while (!tempStack.empty())
		{
			result += tempStack.top();
			tempStack.pop();
		}
		return result;
	}
};