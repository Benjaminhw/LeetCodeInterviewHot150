#pragma once
#include <iostream>
#include <vector>

using namespace std;

//dfs ��ȶ�����
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
			//����1��returnһ��true ����ͨ�����������ע���ʱ2�Ѿ�ͨ�����dfsɢ����ȥ)
			return true;
		}
		//Ϊ0����Ϊ2��ֱ��return
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