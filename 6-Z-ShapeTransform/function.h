/*��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "PAYPALISHIRING" ����Ϊ 3 ʱ���������£�

1P   5A   9H    13N
2A P 6L S 10I I 14G
3Y   7I   11R
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��

1P      7I        13N
2A   6L 8S    12I 14G
3Y 5A   9H 11R
4P      10I

����ʵ��������ַ�������ָ�������任�ĺ�����

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