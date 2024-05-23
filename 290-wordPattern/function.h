#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool wordPattern(string pattern, string s) {
		stringstream tempStream(s);
		vector<string> target;
		string t;
		while (getline(tempStream, t, ' '))
		{
			target.push_back(t);
		}
		if (pattern.size() != target.size())
		{
			return false;
		}

		unordered_map<char, string> hashMapS;
		unordered_map<string, char> hashMapT;

		for (int i = 0; i < pattern.size(); ++i)
		{
			if (hashMapS.find(pattern[i]) == hashMapS.end())
			{
				hashMapS[pattern[i]] = target[i];
			}
			else
			{
				if (hashMapS[pattern[i]] != target[i])
				{
					return false;
				}
			}
			if (hashMapT.find(target[i]) == hashMapT.end())
			{
				hashMapT[target[i]] = pattern[i];
			}
			else
			{
				if (hashMapT[target[i]] != pattern[i])
				{
					return false;
				}
			}
		}
		return true;

	}
};