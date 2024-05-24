/*
* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
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