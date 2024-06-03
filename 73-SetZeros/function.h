/*
����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��
*/

#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		map<int,bool> zeroRow;
		map<int,bool> zeroCol;
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					zeroRow[i]= true;
					zeroCol[j]= true;
				}
			}
		}
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				if (zeroRow[i]||zeroCol[j])
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
};