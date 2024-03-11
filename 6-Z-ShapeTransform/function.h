/*将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

1P   5A   9H    13N
2A P 6L S 10I I 14G
3Y   7I   11R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

1P      7I        13N
2A   6L 8S    12I 14G
3Y 5A   9H 11R
4P      10I

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	string convert(string s, int numRows) {
		//I felt this is a skill trick.
		//I on a different time felt there is no trick.
		//
		string ans;
		if (numRows == 1)
		{
			return s;
		}
		for (int j = 0; j < numRows; ++j)
		{
			for (int i = 0; i * (2 * numRows - 2) + j < s.size(); ++i)
			{
				//go through the whole string
				ans.push_back(s[i * (2 * numRows - 2) + j]);
				if (j != 0 && j != numRows - 1 && (i + 1) * (2 * numRows - 2) - j < s.size())
				{
					ans.push_back(s[(i + 1) * (2 * numRows - 2) - j]);
				}
			}
		}
		return ans;
	}
};