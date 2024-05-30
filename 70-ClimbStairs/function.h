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

		//���Դ�1��ʼ�� �ӵ��Ǹ��ض�
		int p = 0, q = 0, r = 1;
		// ��һ����ʱ����1  p��q�洢ǰ���εĽ��
		for (int i = 1; i <= n; ++i)
		{
			// 0��ʱ���Ƿ�ָ1��ʱ��
			p = q;
			q = r;
			r = q + p;
		}
		return r;
	}
};