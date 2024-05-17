/*����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��

��ĸ�����ֶ�������ĸ�����ַ���

����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	bool isPalindrome(string s) {
		string firstSequence;
		string secondSequence;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		for (auto& x : s)
		{
			if (isalpha(x) || isdigit(x))
			{
				firstSequence.push_back(x);
			}
		}
		secondSequence = firstSequence;
		reverse(firstSequence.begin(),firstSequence.end());
		if (secondSequence == firstSequence)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};