/*
* ����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��

������
��ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

���磬121 �ǻ��ģ��� 123 ���ǡ�
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:

	bool isPalindrome(int x) {
		//80% ShuanQ
		auto s = to_string(x);
		string ss = s;
		reverse(ss.begin(), ss.end());
		if (ss == s)
		{
			return true;
		}
		else
		{
			return false;
		}

		//8.22% VeryGood
		/*stack<char> tempStack;
		tempStack.push('?');
		if (s.size() == 1)
		{
			return true;
		}
		if (s.size() % 2 != 0)
		{
			int o = (s.size() - 1) / 2;
			s.erase(o, 1);
		}
		int u = (s.size() - 1) / 2;
		for (int i = 0; i < s.size(); ++i)
		{
			if (i <= u)
			{
				tempStack.push(s[i]);
			}
			else if (i > u)
			{
				if (tempStack.top() == s[i])
				{
					tempStack.pop();
				}
				else
				{
					return false;
				}
			}
		}
		if (tempStack.size() == 1)
		{
			return true;
		}
		return false;*/
	}
};