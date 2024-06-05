/*
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend]
表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
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

	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0)
		{
			return 0;
		}
		else if (points.size() == 1)
		{
			return 1;
		}
		sort(points.begin(), points.end(), cmp());
		int rangeStart = points[0][0], rangeEnd = points[0][1], ans = 1;
		//Need to find these intervals' overlapped part.
		for (int i = 1; i < points.size(); ++i)
		{
			while (i < points.size() && points[i][0] <= rangeEnd)
			{
				rangeStart = points[i][0];
				rangeEnd = min(rangeEnd, points[i][1]);
				++i;
			}
			if (i >= points.size())
			{
				break;
			}
			++ans;
			rangeStart = points[i][0];
			rangeEnd = points[i][1];
		}
		return ans;
	}
};