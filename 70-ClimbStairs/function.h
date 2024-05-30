#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {

		//// 35/45 
		//if (n == 1)
		//{
		//	return 1;
		//}
		//else if (n == 2)
		//{
		//	return 2;
		//}
		//return climbStairs(n - 2) + climbStairs(n - 1);

		//可以从1开始加 加到那个地儿
		int p = 0, q = 0, r = 1;
		// 第一步的时候是1  p和q存储前两次的结果
		for (int i = 1; i <= n; ++i)
		{
			// 0的时候是泛指1的时候
			p = q;
			q = r;
			r = q + p;
		}
		return r;
	}
};