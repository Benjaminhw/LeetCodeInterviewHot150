/*
给定一个包含小写英文字母的字符串 s 以及一个矩阵 shift，其中 shift[i] = [direction, amount]：

direction 可以为 0 （表示左移）或 1 （表示右移）。
amount 表示 s 左右移的位数。
左移 1 位表示移除 s 的第一个字符，并将该字符插入到 s 的结尾。
类似地，右移 1 位表示移除 s 的最后一个字符，并将该字符插入到 s 的开头。
对这个字符串进行所有操作后，返回最终结果。

*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	void ultraReverse(string& s, bool right, int n)//n为尾部分段的位数
	{
		//注意这里可能会移动超过字符串尺寸的位数
		n = n % s.size();
		int rightMove = 0;
		if (right)
		{
			rightMove = n;
		}
		else
		{
			rightMove = s.size() - n;
		}
		//reverse 左闭右开
		reverse(s.begin(), s.begin() + s.size() - rightMove); //有点怀疑有没有问题
		reverse(s.begin() + s.size() - rightMove, s.end());
		reverse(s.begin(), s.end());
	}

	string stringShift(string s, vector<vector<int>>& shift)
	{
		for (auto& x : shift)
		{
			ultraReverse(s, x[0], x[1]);
		}
		return s;
	}
};