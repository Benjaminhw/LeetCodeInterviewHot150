/*
�����ж�һ�� 9 x 9 �������Ƿ���Ч��ֻ��Ҫ �������¹��� ����֤�Ѿ�����������Ƿ���Ч���ɡ�

���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��


ע�⣺

һ����Ч�������������ѱ���䣩��һ���ǿɽ�ġ�
ֻ��Ҫ�������Ϲ�����֤�Ѿ�����������Ƿ���Ч���ɡ�
�հ׸��� '.' ��ʾ��
*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<char, int> toVerify;
		for (auto& x : board)
		{
			toVerify.clear();
			for (auto& y : x)
			{
				//map��Ĭ�ϳ�ֵ��0
				if (y != '.')
				{
					if (++toVerify[y] > 1)
					{
						return false;
					}
				}
			}
		}
		for (int i = 0; i < 9; ++i)
		{
			toVerify.clear();
			for (int j = 0; j < 9; ++j)
			{
				if (board[j][i] != '.')
				{
					if (++toVerify[board[j][i]] > 1)
					{
						return false;
					}
				}
			}
		}
		for (int n = 0; n < 3; ++n)
		{
			for (int m = 0; m < 3; ++m)
			{
				toVerify.clear();
				for (int i = n * 3; i < (n + 1) * 3; ++i)
				{
					for (int j = m * 3; j < (m + 1) * 3; ++j)
					{
						if (board[j][i] != '.')
						{
							if (++toVerify[board[j][i]] > 1)
							{
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}
};