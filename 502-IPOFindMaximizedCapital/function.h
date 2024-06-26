/*
假设 力扣（LeetCode）即将开始 IPO 。为了以更高的价格将股票卖给风险投资公司，力扣 
希望在 IPO 之前开展一些项目以增加其资本。 由于资源有限，它只能在 IPO 之前完成最多 k 个
不同的项目。帮助 力扣 设计完成最多 k 个不同项目后得到最大总资本的方式。

给你 n 个项目。对于每个项目 i ，它都有一个纯利润 profits[i] ，和启动该项目需要的
最小资本 capital[i] 。

最初，你的资本为 w 。当你完成一个项目时，你将获得纯利润，且利润将被添加到你的总资本中。

总而言之，从给定项目中选择 最多 k 个不同项目的列表，以 最大化最终资本 ，
并输出最终可获得的最多资本。

答案保证在 32 位有符号整数范围内。
*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		vector<pair<int, int>> pairArray;
		for (int i = 0; i < profits.size(); ++i)
		{
			pairArray.push_back({capital[i],profits[i]});
		}
		sort(pairArray.begin(), pairArray.end());
		//很紧张 第一次用优先队列呢~
		priority_queue<int, vector<int>, less<int>> priorityQueue;

		int curr = 0;
		for (int i = 0; i < k; ++i)
		{
			//建堆 把能做的项目放到堆里来做 注意这里还没有开始选要做哪个项目
			//注意这里curr保证所有项目只过一次
			while (curr < profits.size() && pairArray[curr].first <= w)
			{
				priorityQueue.push(pairArray[curr].second);
				++curr;
			}
			if (!priorityQueue.empty())
			{
				w += priorityQueue.top();
				priorityQueue.pop();
			}
			else
			{
				break;
			}
		}
		return w;
	}
};