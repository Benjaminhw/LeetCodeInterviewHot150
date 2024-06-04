/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
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