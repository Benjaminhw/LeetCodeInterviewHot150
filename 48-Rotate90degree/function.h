/*
����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�

������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��
*/
#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//n*n
		int n = matrix.size();
		int tempInt;
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				tempInt = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tempInt;
			}
		}
		for (auto& x : matrix)
		{
			reverse(x.begin(), x.end());
		}
	}
};/*
����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�
������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��


��֪��Ϊʲô��һ�۾��뵽��ô����....�ȰѾ����Ԫ�ذ��նԽ��߷�תһ�£�Ȼ������������Ϳ�����
*/
#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//n*n
		int n = matrix.size();
		int tempInt;
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				tempInt = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tempInt;
			}
		}
		for (auto& x : matrix)
		{
			reverse(x.begin(), x.end());
		}
	}
};