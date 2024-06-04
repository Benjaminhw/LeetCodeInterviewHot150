/*
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ��
����ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��

ʾ�� 1��

���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
�����[[1,6],[8,10],[15,18]]
���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
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
		int i = 1, rangeStart = intervals[0][0], rangeEnd = intervals[0][1];
		while (i < intervals.size())
		{
			while (i < intervals.size() && intervals[i][0] <= intervals[i - 1][1])
			{
				rangeEnd = max(rangeEnd, intervals[i][1]);
				++i;
			}
			vector<int> tempVecInt = { rangeStart,rangeEnd };
			ans.emplace_back(tempVecInt);
			rangeStart = intervals[i][0];
			rangeEnd = intervals[i][1];
			++i;
		}
		//last one
		vector<int> tempVecInt = { rangeStart,rangeEnd };
		ans.emplace_back(tempVecInt);
		return ans;
	}
};