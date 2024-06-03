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

	bool ifContains(unordered_map<char, int>& S, unordered_map<char, int>& sin, char& preChar)
	{
		if (S.find(preChar) == S.end() && preChar != '?')
		{
			return false;
		}
		for (auto& x : sin)
		{
			if (S.find(x.first) != S.end())
			{
				if (S[x.first] < x.second)
				{
					preChar = x.first;
					return false;
				}
			}
			else
			{
				preChar = x.first;
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

		int i = 0, j = 0, answeri = 0, answerj = 0;


		while (i < t.size())
		{
			addChar(s[i], tempMap);
			addChar(t[i], theMap);
			++i;
		}

		bool tempBooL = true;
		char preChar = '?';

		while (i <= s.size())
		{
			if (tempBooL && ifContains(tempMap, theMap, preChar)) //tempBool
			{
				while (j < i && j < s.size())
				{
					if (answeri - answerj > i - j || (answeri == 0 && answerj == 0))
					{
						answeri = i;
						answerj = j;
					}
					if (theMap.find(s[j]) != theMap.end())
					{
						deleteChar(s[j], tempMap);
						if (tempMap.find(s[j]) == tempMap.end())
						{
							++j;
							break;
						}
						else
						{
							if (tempMap[s[j]] < theMap[s[j]])
							{
								++j;
								break;
							}
						}
					}
					++j;
				}
			}
			if (i < s.size())
			{
				if (theMap.find(s[i]) == theMap.end())
				{
					tempBooL = false;
				}
				else
				{
					addChar(s[i], tempMap);
					tempBooL = true;
				}
			}
			++i;
		}
		ans = s.substr(answerj, answeri - answerj);
		return ans;
	}
};