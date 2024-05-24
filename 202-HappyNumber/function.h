/*
* ��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

���������� ����Ϊ��

����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
���������� ���Ϊ 1����ô��������ǿ�������
��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��
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