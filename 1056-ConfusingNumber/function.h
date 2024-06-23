#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	bool isConfusing(char& x)
	{
		if (x == '0' || x == '1' || x == '6' || x == '8' || x == '9')
		{
			if (x == '6')
			{
				x = '9';
			}
			else if (x == '9')
			{
				x = '6';
			}
			return true;
		}
		return false;
	}
	bool confusingNumber(int n) {
		int m = n;
		auto x = std::to_string(n);
		for (auto& y : x)
		{
			if (!isConfusing(y))
			{
				return false;
			}
		}
		reverse(x.begin(), x.end());
		int l = atoi(x.c_str());
		if (l == m)
		{
			return false;
		}
		return true;
	}
};