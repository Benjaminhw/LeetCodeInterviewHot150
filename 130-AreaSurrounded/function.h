/*
����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ��ɣ����� ���� ��Χ�Ƶ�����

���ӣ�һ����Ԫ����ˮƽ��ֱ���������ڵĵ�Ԫ�����ӡ�
������������ '0' �ĵ�Ԫ�����γ�һ������
Χ�ƣ������������ 'X' ��Ԫ�� ����������򣬲���������û���κε�Ԫ��λ�� board ��Ե��
������� 'X' ��Ԫ��Χ�ơ�
ͨ����������� board �е����� 'O' �滻Ϊ 'X' �� ����Χ�Ƶ�����

*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

//��̫��˼·
//ȷʵ��һ��˼·�ϵĶ���������δ����Χ��'0'���Ǻͱ߽��ϵ�0�����ģ��Դ�Ϊ˼·���Ա߽��ϵ�'0'
//��DFS�����������

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
		//���0��O�����������
		if (grid[i][j] == 'O')
		{
			grid[i][j] = 'S';
			DFS(grid, i - 1, j);
			DFS(grid, i + 1, j);
			DFS(grid, i, j - 1);
			DFS(grid, i, j + 1);
			//����1��returnһ��true ����ͨ�����������ע���ʱS�Ѿ�ͨ�����dfsɢ����ȥ)
			return true;
		}
		//��Ϊ0��ֱ�ӽ���
		else
		{
			return false;
		}
	}

	void solve(vector<vector<char>>& board) {
		//�߽�DFS
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