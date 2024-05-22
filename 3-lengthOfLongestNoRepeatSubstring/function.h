#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i = 0, j = 0;
		int result = 0,tempCount=0;
		map<char, bool> tempMap;
		while (j < s.size())
		{
			//
			if (tempMap.find(s[j]) == tempMap.end())
			{
				tempMap[s[j]] = true;
				++tempCount;
				if (tempCount > result)
				{
					result = tempCount;
				}
			}
			else
				//找到了
			{
				while (i < j)
				{
					--tempCount;
					tempMap.erase(s[i]);
					
					if (s[i] == s[j])
					{
						++i;
						--j;
						break;
					}
					++i;
					//debug一年
					//--j;
				}
			}
			++j;
		}
		return result;
	}
};