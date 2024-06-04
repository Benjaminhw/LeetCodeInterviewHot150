/*
根据 百度百科 ， 生命游戏 ，简称为 生命 ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool isInRange(int i, int j, vector<vector<int>>& boardCopy)
	{
		if (i < 0 || j < 0 || i >= boardCopy.size() || boardCopy.size() == 0 || j >= boardCopy[0].size())
		{
			return false;
		}
		return true;
	}

	int isAlive(int i, int j, vector<vector<int>>& boardCopy)
	{
		int Count = 0;
		vector<int> row = { i - 1,i - 1,i - 1,i,    i,    i + 1,i + 1,i + 1 };
		vector<int> col = { j - 1,j,    j + 1,j - 1,j + 1,j - 1,j,    j + 1 };
		for (int k = 0; k < row.size(); ++k)
		{
			int aroundi = row[k], aroundj = col[k];
			if (isInRange(aroundi, aroundj, boardCopy))
			{
				if (boardCopy[aroundi][aroundj] == 1)
				{
					++Count;
				}
			}
		}
		if (Count < 2)
		{
			return 0;
		}
		else if (Count == 2)
		{
			return 1;
		}
		else if (Count == 3)
		{
			return -1;
		}
		else if (Count <= 8)
		{
			return 0;
		}
		return 0;
	}

	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> ans;
		for (int i = 0; i < board.size(); ++i)
		{
			vector<int> tempInt;
			for (int j = 0; j < board[i].size(); ++j)
			{
				int tempx = isAlive(i, j, board);
				if (board[i][j])
				{
					if (tempx != 0)
					{
						tempInt.emplace_back(1);
					}
					else
					{
						tempInt.emplace_back(0);
					}
				}
				else
				{
					if (tempx == -1)
					{
						tempInt.emplace_back(1);
					}
					else
					{
						tempInt.emplace_back(0);
					}
				}
			}
			ans.emplace_back(tempInt);
		}
		board = ans;
	}
};