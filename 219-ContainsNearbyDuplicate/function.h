/*
* ����һ���������� nums ��һ������ k ���ж��������Ƿ�������� ��ͬ������ i �� j ������ nums[i] == nums[j] �� abs(i - j) <= k ��
������ڣ����� true �����򣬷��� false ��
*/
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int i = 0, j = 0;
		//the slippery window
		unordered_map<int, int> hashMap;
		while (j <= k && j < nums.size())
		{
			if (hashMap.find(nums[j]) == hashMap.end())
			{
				hashMap[nums[j]] = 1;
			}
			else
			{
				return true;
			}
			++j;
		}
		while (j < nums.size())
		{
			hashMap.erase(nums[i]);
			if (hashMap.find(nums[j]) == hashMap.end())
			{
				hashMap[nums[j]] = 1;
			}
			else
			{
				return true;
			}
			++i;
			++j;
		}
		return false;
	}
};