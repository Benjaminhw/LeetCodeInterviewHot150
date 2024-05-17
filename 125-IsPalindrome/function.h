/*如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	bool isPalindrome(string s) {
		string firstSequence;
		string secondSequence;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		for (auto& x : s)
		{
			if (isalpha(x) || isdigit(x))
			{
				firstSequence.push_back(x);
			}
		}
		secondSequence = firstSequence;
		reverse(firstSequence.begin(),firstSequence.end());
		if (secondSequence == firstSequence)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};