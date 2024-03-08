#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		vector<string> words;
		string tempString;
		for (int i = 0; i < s.size(); ++i)
		{
			//use two while circulate to process blanks and words
			while (i < s.size() && s[i] == ' ')
			{
				++i;
			}
			while (i < s.size() && s[i] != ' ')
			{
				tempString += s[i];
				++i;
			}
			if (!tempString.empty())
			{
				words.push_back(tempString);
				tempString = "";
			}
		}
		s = "";
		if (words.empty())
		{
			return s;
		}
		s += words[words.size() - 1];
		for (int i = words.size() - 2; i >= 0; --i)
		{
			s += " ";
			s += words[i];
		}
		return s;
	}
};