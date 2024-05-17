/*�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�

�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���

���ף�

����д�������� S������ S1, S2, ... , Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�����������£���������ı���룿*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i = 0, j = 0;
		if (s.empty())
		{
			return true;
		}
		while (i < t.size() && j < s.size())
		{
			if (t[i] == s[j])
			{
				++j;
				if (j >= s.size())
				{
					return true;
				}
			}
			++i;
		}
		return false;
	}
};