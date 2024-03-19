/*给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。*/

//kmp

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
	int next[];
	void getNext(const string& p, int next[])
	{
		int len = (int)p.size();
		next[0] = -1;
		int k = -1;
		int j = 0;
		while (j < len - 1)
		{
			if (k == -1 || p[j] == p[k])
			{
				++j;
				++k;
				next[j] = k;//You have to realize that pre and the post are in the same order.
			}
			else
			{
				k = next[k];//Here it is a reusing of iteself. regard itself as the table to look for.
			}
		}

	}
public:
	int strStr(string haystack, string needle) {
		int j = 0, cmp;
		const int x = (const int)haystack.size();

		int next[5000] = { 0 };
		//build the next array. It's very important to record and comprehand the whole process.
		getNext(needle, next);

		for (int i = 0; i < haystack.size(); ++i)
		{
			if (haystack[i] == needle[j])
			{
				int temp = i;
				while (i < haystack.size() && j < needle.size() && haystack[i] == needle[j])
				{
					if (j == needle.size() - 1)
					{
						return temp;
					}
					++i;
					++j;
				}
				j = 0;
				--i;
			}
		}
		return -1;
	}
};