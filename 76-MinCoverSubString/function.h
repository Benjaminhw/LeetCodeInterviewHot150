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

class Solution {
public:
	void addChar(char x, unordered_map<char, int> m) {

	}
	string minWindow(string s, string t) {
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

		for (int i = 0; i < t.size(); ++i)
		{
			if (tempMap.find(s[i]) == tempMap.end())
			{
				tempMap[s[i]] = 1;
			}
			else
			{
				++tempMap[s[i]];
			}
		}
	}
};