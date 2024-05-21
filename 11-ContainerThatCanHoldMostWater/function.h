/*
����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��

�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��

�����������Դ�������ˮ����

˵�����㲻����б������

 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {
		int realHeight = 0;
		int result = 0;

		////exhaustive search 55/62
		//for (int j = 0; j < height.size(); ++j)
		//{
		//	for (int i = 0; i < j; ++i)
		//	{
		//		realHeight = min(height[i], height[j]);
		//		auto temp = abs(j - i) * realHeight;
		//		if (temp > result)
		//		{
		//			result = temp;
		//		}
		//	}
		//}

		if (height.size() == 2)
		{
			return min(height[1], height[0]);
		}
		if (height.size() == 1)
		{
			return 0;
		}

		//�������ƶ��̰壬ˮ�۵Ķ̰���ܱ������¸�ˮ�۵������������
		//�������ƶ����壬ˮ�۵Ķ̰岻����С������¸�ˮ�۵����һ����С��

		//two pointers? compare the height's increment and the width's decrease.
		//A left pointer and a right pointer.
		int leftPointer = 0, rightPointer = height.size()-1;
		while (leftPointer != rightPointer)
		{
			if (height[leftPointer] > height[rightPointer])
			{
				--rightPointer;
			}
			else
			{
				++leftPointer;
			}
			auto S = min(height[leftPointer], height[rightPointer]) * (rightPointer - leftPointer);
			if (S > result)
			{
				result = S;
			}
		}
		
		return result;
	}
};