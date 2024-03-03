#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
你需要按照以下要求，给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。*/


class Solution {
public:
	int candy(vector<int>& ratings) {
		int candyCount = 0, tempCount = 1;
		vector<int> Max = ratings;
		if (ratings.size() == 1)
		{
			//Candy[0] = 1;
			return 1;
		}
		Max[0] = 1;
		for (int i = 1; i < ratings.size(); ++i)
		{

			if (ratings[i] > ratings[i - 1])
			{
				++tempCount;
				Max[i] = tempCount;
			}
			else
			{
				tempCount = 1;
				Max[i] = tempCount;
			}
		}
		tempCount = 1;
		for (int i = ratings.size() - 2; i >= 0; --i)
		{
			if (ratings[i] > ratings[i + 1])
			{
				++tempCount;
				Max[i] = max(tempCount, Max[i]);
			}
			else
			{
				tempCount = 1;
				Max[i] = max(Max[i], tempCount);
			}
		}
		for (auto& x : Max)
		{
			candyCount += x;
		}
		return candyCount;
	}
};