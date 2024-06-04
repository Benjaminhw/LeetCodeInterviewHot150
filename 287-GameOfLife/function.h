/*
���� �ٶȰٿ� �� ������Ϸ �����Ϊ ���� ����Ӣ����ѧ��Լ�����ζ١������� 1970 �귢����ϸ���Զ�����

����һ������ m �� n �����ӵ���壬ÿһ�����Ӷ����Կ�����һ��ϸ����ÿ��ϸ��������һ����ʼ״̬�� 1 ��Ϊ ��ϸ�� ��live������ 0 ��Ϊ ��ϸ�� ��dead����ÿ��ϸ������˸�����λ�ã�ˮƽ����ֱ���Խ��ߣ���ϸ������ѭ�����������涨�ɣ�

�����ϸ����Χ�˸�λ�õĻ�ϸ�����������������λ�û�ϸ��������
�����ϸ����Χ�˸�λ����������������ϸ�������λ�û�ϸ����Ȼ��
�����ϸ����Χ�˸�λ���г���������ϸ�������λ�û�ϸ��������
�����ϸ����Χ������������ϸ�������λ����ϸ�����
��һ��״̬��ͨ������������ͬʱӦ���ڵ�ǰ״̬�µ�ÿ��ϸ�����γɵģ�����ϸ���ĳ�����������ͬʱ�����ġ����� m x n ������� board �ĵ�ǰ״̬��������һ��״̬��
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