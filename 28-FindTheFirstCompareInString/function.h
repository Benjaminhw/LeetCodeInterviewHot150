/*���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ����
��� needle ���� haystack ��һ���֣��򷵻�  -1 ��*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		int j = 0, cmp;
		for (int i = 0; i < haystack.size(); ++i)
		{
			if (haystack[i] == needle[j])
			{
				int temp = i;
				while (i < haystack.size() && j < needle.size() && haystack[i] == needle[j])
				{
					if (j == needle.size() - 1)
					{
						return temp;
					}
					++i;
					++j;
				}
				j = 0;
				--i;
			}
		}
		return -1;
	}
};