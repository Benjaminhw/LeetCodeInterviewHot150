/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> hashMapS;
		unordered_map<char, char> hashMapT;
		if (s.size() != t.size())
		{
			return false;
		}
		for (int i = 0; i < s.size(); ++i)
		{
			if (hashMapS.find(s[i]) == hashMapS.end())
			{
				hashMapS[s[i]] = t[i];
			}
			else
			{
				if (hashMapS[s[i]] != t[i])
				{
					return false;
				}
			}
			if (hashMapT.find(t[i]) == hashMapT.end())
			{
				hashMapT[t[i]] = s[i];
			}
			else
			{
				if (hashMapT[t[i]] != s[i])
				{
					return false;
				}
			}
		}
		return true;
	}
};