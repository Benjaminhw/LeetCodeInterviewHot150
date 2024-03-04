/*�������ְ������������ַ�: I�� V�� X�� L��C��D �� M��

�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
���磬 �������� 2 д�� II ����Ϊ�������е� 1 ��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��

ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������

I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90��
C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��
����һ���������֣�����ת����������*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
private:
	unordered_map<string, int> RomanCharactorMap =
	{
		{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},
		{"D",500},{"M",1000},{"IV",4},{"IX",9},{"XL",40},
		{"XC",90},{"CD",400},{"CM",900}
	};

public:
	int romanToInt(string s) {
		string tempString;
		int answer = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			char x = s[i];
			char y = 'S';
			(i + 1) < s.size() ? y = s[i + 1] : 0;
			tempString.push_back(x);
			if ((i != s.size() - 1) &&
				(
					((x == 'I') && (y == 'V' || y == 'X')) ||
					((x == 'X') && (y == 'L' || y == 'C')) ||
					((x == 'C') && (y == 'D' || y == 'M'))
					)
				)
			{
				//If it is the Complex kind, skip this round to the next round.
				continue;
			}
			//Default: Consider tempString is already in the map.
			answer += RomanCharactorMap[tempString];
			tempString = "";
		}
		return answer;
	}
};