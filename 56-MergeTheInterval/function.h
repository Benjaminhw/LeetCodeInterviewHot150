/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	class cmp {
	public:
		bool operator()(vector<int> a, vector<int> b)
		{
			return a[0] < b[0];
		}
	};

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//interesting
		if (intervals.size() == 0)
		{
			return intervals;
		}
		sort(intervals.begin(), intervals.end(), cmp());
		vector<vector<int>> ans;
		vector<int> tempVecInt;
		int i = 1, rangeStart = intervals[0][0], rangeEnd = intervals[0][1];
		while (i < intervals.size())
		{
			while (i < intervals.size() && intervals[i][0] <= rangeEnd)
			{
				rangeEnd = max(rangeEnd, intervals[i][1]);
				++i;
				if (i >= intervals.size())
				{
					goto labelA;
				}
			}
			tempVecInt = { rangeStart,rangeEnd };
			ans.emplace_back(tempVecInt);
			rangeStart = intervals[i][0];
			rangeEnd = intervals[i][1];
			++i;
		}
		//last one
	labelA:
		tempVecInt = { rangeStart,rangeEnd };
		ans.emplace_back(tempVecInt);
		return ans;
	}
};