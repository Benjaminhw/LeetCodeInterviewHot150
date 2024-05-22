/*
* ����һ������ n ���������������һ�������� target ��

�ҳ����������������ܺʹ��ڵ��� target �ĳ�����С�� ����
������
 [numsl, numsl+1, ..., numsr-1, numsr] ���������䳤�ȡ���������ڷ��������������飬���� 0 ��
*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;


class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		map<vector<int>, int> hashMap;
		int tempSum = 0, result = 0;

		//double pointers (slip window)
		int i = 0, j = 0;
		while (j < nums.size())
		{
			tempSum += nums[j];
			while (i<j && tempSum > target)
			{
				if (result == 0 || j - i + 1 < result)
				{
					result = j - i;
				}
				tempSum -= nums[i];
				++i;
			}
			++j;
		}
		return result;

		//// exhaustive search 18/21  //miss the condition: positive number
		//// no middle use
		//for (int i = 0; i < nums.size(); ++i)
		//{
		//	tempSum += nums[i];
		//	//the first means the position, the second means the width of the window
		//	hashMap[{i, i + 1}] = tempSum;
		//	if (tempSum >= target && (result == 0 || i + 1 < result))
		//	{
		//		result = i + 1;
		//	}
		//}

		////triangle
		//tempSum = 0;
		//for (int j = 0; j < nums.size(); ++j)
		//{
		//	tempSum += nums[j];
		//	for (int i = j; i < nums.size(); ++i)
		//	{
		//		hashMap[{i, i - j}] = hashMap[{i, i + 1}] - tempSum;
		//		if (hashMap[{i, i - j}] >= target && (result == 0 || i - j < result))
		//		{
		//			result = i - j;
		//		}
		//	}
		//}

		return result;
	}
};