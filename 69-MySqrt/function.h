/*
����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��

���ڷ������������������ֻ���� �������� ��С�����ֽ��� ��ȥ ��

ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x ** 0.5 ��
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int mySqrt(int x) {
		return (int)pow(x, 0.5);
	}
};