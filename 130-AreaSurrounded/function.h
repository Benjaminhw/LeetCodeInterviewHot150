/*
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：

连接：一个单元格与水平或垂直方向上相邻的单元格连接。
区域：连接所有 '0' 的单元格来形成一个区域。
围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，
则该区域被 'X' 单元格围绕。
通过将输入矩阵 board 中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。

*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

//不太有思路
//确实是一个思路上的东西，所有未被包围的'0'都是和边界上的0相连的，以此为思路，对边界上的'0'
//做DFS深度优先搜索

class Solution {
public:
	bool judgeIfLand(vector<vector<char>>& grid, int i, int j)
	{
		if (i < grid.size() && j < grid[i].size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DFS(vector<vector<char>>& grid, int i, int j)
	{
		if (!judgeIfLand(grid, i, j))
		{
			return false;
		}
		//这个0和O长得是真的像
		if (grid[i][j] == 'O')
		{
			grid[i][j] = 'S';
			DFS(grid, i - 1, j);
			DFS(grid, i + 1, j);
			DFS(grid, i, j - 1);
			DFS(grid, i, j + 1);
			//遇到1就return一次true 后续通过这个计数（注意此时S已经通过这次dfs散布出去)
			return true;
		}
		//不为0的直接结束
		else
		{
			return false;
		}
	}

	void solve(vector<vector<char>>& board) {
		//边界DFS
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if ((i == 0 || i == board.size() - 1) || 
					(j == 0 || j == board[0].size() - 1))
				{
					DFS(board, i, j);
				}
			}
		}
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (board[i][j]=='O')
				{
					board[i][j] = 'X';
				}
				else if (board[i][j] == 'S')
				{
					board[i][j] = 'O';
				}
			}
		}
	}
};