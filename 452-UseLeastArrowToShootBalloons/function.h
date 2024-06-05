/*
��һЩ������������һ���� XY ƽ���ʾ��ǽ���ϡ�ǽ���ϵ������¼���������� points ������points[i] = [xstart, xend]
��ʾˮƽֱ���� xstart �� xend֮��������㲻֪�������ȷ�� y ���ꡣ

һ֧������������ x ��Ӳ�ͬ�� ��ȫ��ֱ ������������� x �����һ֧��������һ�������ֱ���Ŀ�ʼ�ͽ�������Ϊ xstart��xend��
������  xstart �� x �� xend���������ᱻ ���� ����������Ĺ��������� û������ �� ����һ�������֮�󣬿������޵�ǰ����

����һ������ points ����������������������������� ��С ������ ��
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