/*
����һ������СдӢ����ĸ���ַ��� s �Լ�һ������ shift������ shift[i] = [direction, amount]��

direction ����Ϊ 0 ����ʾ���ƣ��� 1 ����ʾ���ƣ���
amount ��ʾ s �����Ƶ�λ����
���� 1 λ��ʾ�Ƴ� s �ĵ�һ���ַ����������ַ����뵽 s �Ľ�β��
���Ƶأ����� 1 λ��ʾ�Ƴ� s �����һ���ַ����������ַ����뵽 s �Ŀ�ͷ��
������ַ����������в����󣬷������ս����

*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	void ultraReverse(string& s, bool right, int n)//nΪβ���ֶε�λ��
	{
		//ע��������ܻ��ƶ������ַ����ߴ��λ��
		n = n % s.size();
		int rightMove = 0;
		if (right)
		{
			rightMove = n;
		}
		else
		{
			rightMove = s.size() - n;
		}
		//reverse ����ҿ�
		reverse(s.begin(), s.begin() + s.size() - rightMove); //�е㻳����û������
		reverse(s.begin() + s.size() - rightMove, s.end());
		reverse(s.begin(), s.end());
	}

	string stringShift(string s, vector<vector<int>>& shift)
	{
		for (auto& x : shift)
		{
			ultraReverse(s, x[0], x[1]);
		}
		return s;
	}
};