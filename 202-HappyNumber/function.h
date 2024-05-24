/*
* 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
	int maxRound = 20;
	int count = 0;
	bool isHappy(int n) {
		//build a hashmap to accelerate the process.
		unordered_map<int, bool> hashMap;
		auto s = to_string(n);
		//set false after maxRound's rounds.
		int tempSum = 0;
		for (auto x : s)
		{
			string sx;
			sx.push_back(x);
			tempSum += pow(atoi(sx.c_str()), 2);
		}
		if (tempSum == 1)
		{
			return true;
		}
		else {
			++count;
			if (count > maxRound)
			{
				return false;
			}
			return isHappy(tempSum);
			
		}
		return false;
	}
};