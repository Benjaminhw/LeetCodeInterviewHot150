/*给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		int j = 0, cmp;
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