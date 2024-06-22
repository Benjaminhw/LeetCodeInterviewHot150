#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int Proc(const vector<int>& arr, int diff)
{
	vector<int> arrCopy = arr;
	// �ڴ������Ĵ���
	sort(arrCopy.begin(), arrCopy.end());
	//˫ָ��

	if (arrCopy.size() <= 1)
	{
		return 0;
	}
	int i = 0, j = 1;
	int ans = 0;
	if (diff >= 0)
	{
		while (i < arrCopy.size() && i < j && j < arrCopy.size())
		{
			while (j < arrCopy.size() && arrCopy[j] - arrCopy[i] < diff)
			{
				++j;
			}
			while (j < arrCopy.size() && arrCopy[j] - arrCopy[i] == diff)
			{
				++ans;
				++j;
			}
			++i;
		}
	}
	else
	{
		while (i < arrCopy.size() && i < j && j < arrCopy.size())
		{
			while (j < arrCopy.size() && arrCopy[i] - arrCopy[j] > diff)
			{
				++j;
			}
			while (j < arrCopy.size() && arrCopy[i] - arrCopy[j] == diff)
			{
				++ans;
				++j;
			}
			++i;
		}
	}
	return ans;
}