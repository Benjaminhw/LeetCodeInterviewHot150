/*
* 给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。



示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。
*/
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
	bool isMapEqual(unordered_map<string, int> A, unordered_map<string, int> B)
	{
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

	vector<int> findSubstring(string s, vector<string>& words) {

		//slipWindows + hashMap
		vector<int> results;
		unordered_map<string, int> hashMap;
		for (auto& x : words)
		{
			//if it can't found
			if (hashMap.find(x) == hashMap.end())
			{
				hashMap[x] = 1;
			}
			//if it is found.
			else
			{
				++hashMap[x];
			}
		}
		if (words.empty())
		{
			return results;
		}
		int start = 0 /*Where the position starts.*/, width = words[0].size(), length = words.size();
		for (;start < width; ++start)
		{
			unordered_map<string, int> tempHashMap;
			int i = start, j = start; //actual pointer 
			while (j < start + length * width && j < s.size())
			{
				auto y = s.substr(j, width);
				if (tempHashMap.find(y)==tempHashMap.end())
				{
					tempHashMap[y] = 1;

				}
				else
				{
					++tempHashMap[y];
				}
				j += width;
			}
			//初建立
			if (isMapEqual(hashMap, tempHashMap))
			{
				results.push_back(i);
			}
			i+=width;
			j+=width;
			while (j <= s.size())
			{
				auto y = s.substr(j - width, width);
				if (tempHashMap.find(y) == tempHashMap.end())
				{
					tempHashMap[y] = 1;
				}
				else
				{
					++tempHashMap[y];
				}
				auto z = s.substr(i - width, width);
				{
					--tempHashMap[z];
					if (tempHashMap[z] <= 0)
					{
						tempHashMap.erase(z);
					}
				}
				if (isMapEqual(hashMap, tempHashMap))
				{
					results.push_back(i);
				}
				i += width;
				j += width;
			}
		}
		return results;
	}
};