/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void returnPosition(int length, int m, int n, int& rx, int& ry)
	{
		if (length <= m)
		{
			rx = length - 1;
			ry = 0;
		}
		else if (length <= m + n - 1)
		{
			rx = m - 1;
			ry = length - m + 1 - 1;
		}
		else if (length <= 2 * m + n - 2)
		{
			rx = m - (length - (m + n - 1) + 1);
			ry = n - 1;
		}
		else if (length <= 2 * m + 2 * n - 4)
		{
			rx = 0;
			ry = n - (length - (2 * m + n - 2) + 1);
		}
		else
		{
			int rxx = 0, ryy = 0, newLength = length - (2 * m + 2 * n - 4);
			returnPosition(newLength, m - 2, n - 2, rxx, ryy);
			rx = rxx + 1;
			ry = ryy + 1;
		}
		if (rx < 0 || ry < 0)
		{
			cout << "error";
		}
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> result;
		int i = 1, m = 0, n = 0;
		int amount = 0;
		for (auto& x : matrix)
		{
			n = x.size();
			amount += x.size();
		}
		m = matrix.size();

		while (i <= amount)
		{
			int posx, posy;
			returnPosition(i, m, n, posx, posy);
			result.emplace_back(matrix[posy][posx]);
			++i;
		}
		return result;
	}
};