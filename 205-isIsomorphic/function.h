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
		unordered_map<char, char> hashMap;
		if (s.size() != t.size())
		{
			return false;
		}
		for (int i = 0; i < s.size(); ++i)
		{
			if (hashMap.find(s[i]) == hashMap.end())
			{
				hashMap[s[i]] = t[i];
			}
			else
			{
				if (hashMap[s[i]] != t[i])
				{
					return false;
				}
			}
		}
		return true;
	}
};