/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/
#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//n*n
		int n = matrix.size();
		int tempInt;
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				tempInt = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tempInt;
			}
		}
		for (auto& x : matrix)
		{
			reverse(x.begin(), x.end());
		}
	}
};/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。


不知道为什么第一眼就想到怎么做了....先把矩阵的元素按照对角线翻转一下，然后再逐行逆序就可以了
*/
#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//n*n
		int n = matrix.size();
		int tempInt;
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				tempInt = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tempInt;
			}
		}
		for (auto& x : matrix)
		{
			reverse(x.begin(), x.end());
		}
	}
};