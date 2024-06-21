#pragma once
#include <iostream>
#include <vector>

using namespace std;

//dfs 类比二叉树
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
		if (grid[i][j] == '1')
		{
			grid[i][j] = '2';
			DFS(grid, i - 1, j);
			DFS(grid, i + 1, j);
			DFS(grid, i, j - 1);
			DFS(grid, i, j + 1);
			//遇到1就return一次true 后续通过这个计数（注意此时2已经通过这次dfs散布出去)
			return true;
		}
		//为0或者为2都直接return
		else
		{
			return false;
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if (DFS(grid, i, j))
				{
					++ans;
				}
			}
		}
		return ans;
	}
};