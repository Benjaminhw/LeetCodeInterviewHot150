/*
�ߵ������� 32 λ�޷��������Ķ�����λ��
*/
#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t r = 0;
		for (int i = 0; i < 32; ++i)
		{
			r = (r << 1) | (n & 1);
			n >>= 1;
		}
	}
};