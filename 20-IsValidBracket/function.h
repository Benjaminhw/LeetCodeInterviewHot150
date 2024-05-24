/*
* ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
*/

#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
	bool isValid(string s) {
		//recursively eliminate the string
		stack<char> theStack;
		theStack.push('x');

		for (auto& x : s)
		{
			if (x == '(')
			{
				theStack.push('(');
			}
			else if (x == '[')
			{
				theStack.push('[');
			}
			else if (x == '{')
			{
				theStack.push('{');
			}
			else if (x == ']')
			{
				if (theStack.top() != '[')
				{
					return false;
				}
				else
				{
					theStack.pop();
				}
			}
			else if (x == '}')
			{
				if (theStack.top() != '{')
				{
					return false;
				}
				else
				{
					theStack.pop();
				}
			}
			else if (x == ')')
			{
				if (theStack.top() != '(')
				{
					return false;
				}
				else
				{
					theStack.pop();
				}
			}
		}
		if (theStack.size() == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};