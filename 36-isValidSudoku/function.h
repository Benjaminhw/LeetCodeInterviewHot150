/*
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）


注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。
*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<char, int> toVerify;
		for (auto& x : board)
		{
			toVerify.clear();
			for (auto& y : x)
			{
				//map会默认初值是0
				if (y != '.')
				{
					if (++toVerify[y] > 1)
					{
						return false;
					}
				}
			}
		}
		for (int i = 0; i < 9; ++i)
		{
			toVerify.clear();
			for (int j = 0; j < 9; ++j)
			{
				if (board[j][i] != '.')
				{
					if (++toVerify[board[j][i]] > 1)
					{
						return false;
					}
				}
			}
		}
		for (int n = 0; n < 3; ++n)
		{
			for (int m = 0; m < 3; ++m)
			{
				toVerify.clear();
				for (int i = n * 3; i < (n + 1) * 3; ++i)
				{
					for (int j = m * 3; j < (m + 1) * 3; ++j)
					{
						if (board[j][i] != '.')
						{
							if (++toVerify[board[j][i]] > 1)
							{
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}
};