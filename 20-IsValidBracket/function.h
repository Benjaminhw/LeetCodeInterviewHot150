/*
* ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	char recurse(string a)
	{
		auto x = a[0];
		a = a.substr(1);
		switch (x)
		{
			'(':
			{
				recurse(a);
				break;
			}
			'[' :
			{
				break;
			}
			'{' :
			{
				break;
			}
			')' :
			{
				break;
			}
			']' :
			{
				break;
			}
			'}' :
			{
				break;
			}
		default:
			break;
		}
	}

	bool isValid(string s) {
		//recursively eliminate the string
		if (s.size() == 0)
		{
			return true;
		}
		 
		isValid(s.substr(1));
	}
};