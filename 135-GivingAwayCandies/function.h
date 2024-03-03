#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*n ������վ��һ�š�����һ���������� ratings ��ʾÿ�����ӵ����֡�
����Ҫ��������Ҫ�󣬸���Щ���ӷַ��ǹ���
ÿ���������ٷ��䵽 1 ���ǹ���
���������������ָ��ߵĺ��ӻ��ø�����ǹ���
�����ÿ�����ӷַ��ǹ������㲢������Ҫ׼���� �����ǹ���Ŀ ��*/


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