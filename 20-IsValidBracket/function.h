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

using namespace std;


class Solution {
public:
	char recurse(string a)
	{
		auto x = a[0];
		a = a.substr(1);
		switch (x)
		{
			'(':
			{
				recurse(a);
				break;
			}
			'[' :
			{
				break;
			}
			'{' :
			{
				break;
			}
			')' :
			{
				break;
			}
			']' :
			{
				break;
			}
			'}' :
			{
				break;
			}
		default:
			break;
		}
	}

	bool isValid(string s) {
		//recursively eliminate the string
		if (s.size() == 0)
		{
			return true;
		}
		 
		isValid(s.substr(1));
	}
};