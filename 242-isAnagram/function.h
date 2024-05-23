#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool isMapEqual(unordered_map<char, int> A, unordered_map<char, int> B)
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

	bool isAnagram(string s, string t) {
		unordered_map<char, int> hashMapS;
		unordered_map<char, int> hashMapT;
		for (auto& x : s)
		{
			if (hashMapS.find(x) == hashMapS.end())
			{
				hashMapS[x] = 1;
			}
			else
			{
				++hashMapS[x];
			}
		}
		for (auto& x : t)
		{
			if (hashMapT.find(x) == hashMapT.end())
			{
				hashMapT[x] = 1;
			}
			else
			{
				++hashMapT[x];
			}
		}
		return isMapEqual(hashMapS, hashMapT);
	}
};