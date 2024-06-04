/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
	bool isMapEqual(unordered_map<char, int>& A, unordered_map<char, int>& B)
	{
		if (A.size() != B.size())
		{
			return false;
		}
		for (auto& x : A)
		{
			if (B.find(x.first) == B.end())
			{
				return false;
			}
			else
			{
				if (B[x.first] != x.second)
				{
					return false;
				}
			}
		}
		return true;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		//sort defeat 70%
		unordered_map<string, int> maps;
		vector<vector<string>> ans;
		int i = 0;
		for (auto& x : strs)
		{
			string tempStr = x;
			sort(x.begin(),x.end());
			if (maps.find(x) != maps.end())
			{
				ans[maps[x]].emplace_back(tempStr);
			}
			else
			{
				maps[x] = i;
				vector<string> tempStrs;
				tempStrs.emplace_back(tempStr);
				ans.emplace_back(tempStrs);
				++i;
			}
		}
		return ans;
		//// compare map？Too Complex defeat 5% //SORT use sort to change! it only has 26 characters or vector
		//vector<unordered_map<char, int>> maps; //the sequence of how it is added.
		////
		//vector<vector<string>> ans;
		//for (auto& x : strs)
		//{
		//	vector<string> tempVecStr;
		//	unordered_map<char, int> tempMap;
		//	for (auto& y : x)
		//	{
		//		++tempMap[y];
		//	}
		//	for (int i = 0; i < maps.size(); ++i)
		//	{
		//		if (isMapEqual(tempMap, maps[i]))
		//		{
		//			ans[i].emplace_back(x);
		//			goto labelA;
		//		}
		//	}
		//	maps.emplace_back(tempMap);
		//	tempVecStr.emplace_back(x);
		//	ans.emplace_back(tempVecStr);
		//labelA:
		//	//cout << "";
		//}
		//return ans;

	}
};