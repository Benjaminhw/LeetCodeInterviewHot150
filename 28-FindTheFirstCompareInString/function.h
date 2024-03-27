/*���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ����
��� needle ���� haystack ��һ���֣��򷵻�  -1 ��*/

//kmp

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void getNext(const string& p, int next[])
	{
		int len = (int)p.size();
		next[0] = -1;

		// k���ᳬ��j
		int k = -1;
		int j = 0;

		while (j < len - 1)
		{ // j does not go back.
			if (k == -1 /*For convenience*/ || p[j] == p[k]) // First one or equal ones.
			{
				++j;
				++k;
				next[j] = k; // You have to realize that pre and the post are in the same order.
			}
			else
			{
				k = next[k]; // Here it is a reusing of iteself. regard itself as the table to look for.
			}
		}
	}

public:
	int strStr(string haystack, string needle) {
		int j = 0, i = 0, cmp;
		const int x = (const int)haystack.size();

		// build the next array. It's very important to record and comprehand the whole process.
		int next[5000] = { 0 };

		// get the next array.
		getNext(needle, next);

		while (i < haystack.size())
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				++i;
				++j;
				if (j >= needle.size())
				{
					return i - j;
				}
			}
			else
			{
				j = next[j];
			}
		}
		return -1;
	}
};