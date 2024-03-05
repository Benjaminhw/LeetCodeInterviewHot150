/*�������ְ������������ַ��� I�� V�� X�� L��C��D �� M��

�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��

ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������

I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90��
C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��
����һ������������תΪ�������֡�*/

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