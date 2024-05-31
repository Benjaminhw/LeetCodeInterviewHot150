/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串

*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	void addChar(char x, unordered_map<char, int> m) {

	}
	string minWindow(string s, string t) {
		if (s.size() < t.size())
		{
			return "";
		}
		else if (s.size() == t.size())
		{
			if (s == t)
			{
				return s;
			}
		}
		unordered_map<char, int> tempMap; //for 遍历tempMap即可
		unordered_map<char, int> theMap;

		for (int i = 0; i < t.size(); ++i)
		{
			if (tempMap.find(s[i]) == tempMap.end())
			{
				tempMap[s[i]] = 1;
			}
			else
			{
				++tempMap[s[i]];
			}
		}
	}
};