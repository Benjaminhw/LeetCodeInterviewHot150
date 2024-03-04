/*���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��*/
#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Consider every column
class Solution {
public:
	int trap(vector<int>& height) {
		vector<int> leftHighestWall;
		leftHighestWall.resize(height.size());
		vector<int> rightHighestWall = height;
		rightHighestWall.resize(height.size());
		int tempMaxHeight = 0;

		//Consider every column. From left to right.
		for (int i = 0; i < height.size() - 1; ++i)
		{
			//Every column has its left highest wall and right highest wall.
			if (height[i] > tempMaxHeight)
			{
				tempMaxHeight = height[i];
			}
			leftHighestWall[i] = tempMaxHeight;
		}
		//From right to left
		tempMaxHeight = 0;
		for (int i = height.size() - 1; i >= 0; --i)
		{
			if (height[i] > tempMaxHeight)
			{
				tempMaxHeight = height[i];
			}
			rightHighestWall[i] = tempMaxHeight;
		}
		int waterVolumn = 0;
		for (int i = 0; i < height.size(); ++i)
		{
			int temp = min(leftHighestWall[i], rightHighestWall[i])-height[i];
			if (temp > 0)
			{
				waterVolumn += temp;
			}
		}
		return waterVolumn;
	}
};