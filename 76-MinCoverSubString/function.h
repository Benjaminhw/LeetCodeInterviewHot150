/*
����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��

ʾ�� 1��

���룺s = "ADOBECODEBANC", t = "ABC"
�����"BANC"
���ͣ���С�����Ӵ� "BANC" ���������ַ��� t �� 'A'��'B' �� 'C'��
ʾ�� 2��

���룺s = "a", t = "a"
�����"a"
���ͣ������ַ��� s ����С�����Ӵ���
ʾ�� 3:

����: s = "a", t = "aa"
���: ""
����: t �������ַ� 'a' ��Ӧ������ s ���Ӵ��У�
���û�з������������ַ��������ؿ��ַ���

*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//265/268 ������֦
class Solution {
public:
	void addChar(char x, unordered_map<char, int>& m) {
		if (m.find(x) == m.end())
		{
			m[x] = 1;
		}
		else
		{
			++m[x];
		}
	}
	void deleteChar(char x, unordered_map<char, int>& m) {
		if (m[x] == 1)
		{
			m.erase(x);
		}
		else
		{
			--m[x];
		}
	}

	bool ifContains(unordered_map<char, int> S, unordered_map<char, int> sin)
	{
		for (auto& x : sin)
		{
			if (S.find(x.first) != S.end())
			{
				if (S[x.first] < x.second)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		string ans = "";
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
		unordered_map<char, int> tempMap; //for ����tempMap����
		unordered_map<char, int> theMap;

		int i = 0, j = 0;

		while (i < t.size())
		{
			addChar(s[i], tempMap);
			addChar(t[i], theMap);
			++i;
		}

		while (i <= s.size())
		{
			if (ifContains(tempMap, theMap))
			{
				while ( j < i && j < s.size())
				{
					if ((ans == "") || ans.size() > i - j)
					{
						ans = s.substr(j, i - j);
					}
					deleteChar(s[j], tempMap);
					if (theMap.find(s[j]) != theMap.end())
					{
						if (tempMap.find(s[j]) == tempMap.end())
						{
							break;
						}
						else
						{
							if (tempMap[s[j]] < theMap[s[j]])
							{
								break;
							}
						}
					}
					++j;
				}
			}
			if (i < s.size())
			{
				addChar(s[i], tempMap);
			}
			++i;
		}
		return ans;
	}
};