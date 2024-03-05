/*罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;


class Solution {
private:
	unordered_map<string, int> RomanCharactorMap =
	{
		{"M",1000},{"CM",900},{"D",500},{"CD",400},
		{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},
		{"IX",9},{"V",5},{"IV",4},{"I",1}
	};
	map<int, string> IDMap =
	{
		{12,"I"},{11,"IV"},{10,"V"},{9,"IX"},{8,"X"},{7,"XL"},{6,"L"},{5,"XC"},{4,"C"},{3,"CD"},
		{2,"D"},{1,"CM"},{0,"M"},
	};
	//int M = 0, D = 0, C = 0, L = 0, X = 0, V = 0, I = 0, IV = 0, IX = 0, XL = 0, XC = 0, CD = 0, CM = 0;

	void Calculate(int& x, string a, int& num)
	{
		x = num / RomanCharactorMap[a];
		num %= RomanCharactorMap[a];
	}
public:

	string intToRoman(int num) {
		int temp = 0;
		vector<int> AnswerInt;
		for (auto& x : IDMap)
		{
			Calculate(temp, x.second, num);
			AnswerInt.emplace_back(temp);
		}
		string AnswerString;
		for (int i=0;i<AnswerInt.size();++i)
		{
			for (int j = 0; j < AnswerInt[i]; ++j)
			{
				AnswerString += IDMap[i];
			}
		}
		return AnswerString;
	}
};