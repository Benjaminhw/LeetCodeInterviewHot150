/*
���������ַ��� s �� t ���ж������Ƿ���ͬ���ġ�

��� s �е��ַ����԰�ĳ��ӳ���ϵ�滻�õ� t ����ô�������ַ�����ͬ���ġ�

ÿ�����ֵ��ַ���Ӧ��ӳ�䵽��һ���ַ���ͬʱ���ı��ַ���˳�򡣲�ͬ�ַ�����ӳ�䵽ͬһ���ַ��ϣ���ͬ�ַ�ֻ��ӳ�䵽ͬһ���ַ��ϣ��ַ�����ӳ�䵽�Լ�����
*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> hashMapS;
		unordered_map<char, char> hashMapT;
		if (s.size() != t.size())
		{
			return false;
		}
		for (int i = 0; i < s.size(); ++i)
		{
			if (hashMapS.find(s[i]) == hashMapS.end())
			{
				hashMapS[s[i]] = t[i];
			}
			else
			{
				if (hashMapS[s[i]] != t[i])
				{
					return false;
				}
			}
			if (hashMapT.find(t[i]) == hashMapT.end())
			{
				hashMapT[t[i]] = s[i];
			}
			else
			{
				if (hashMapT[t[i]] != s[i])
				{
					return false;
				}
			}
		}
		return true;
	}
};