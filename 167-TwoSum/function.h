/*����һ���±�� 1 ��ʼ���������� numbers ���������Ѱ� �ǵݼ�˳������  ��������������ҳ��������֮�͵���Ŀ���� target ������������������������ֱ��� numbers[index1] �� numbers[index2] ���� 1 <= index1 < index2 <= numbers.length ��

�Գ���Ϊ 2 ���������� [index1, index2] ����ʽ�����������������±� index1 �� index2��

����Լ���ÿ������ ֻ��ӦΨһ�Ĵ� �������� ������ �ظ�ʹ����ͬ��Ԫ�ء�

������ƵĽ����������ֻʹ�ó������Ķ���ռ䡣
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {

		//int index1 = 0, index2 = numbers.size()-1;
		//int tempSum = 0;

		////before cut the branch: 19/23

		//for (; index2 < numbers.size(); ++index2)
		//{
		//	for (index1 = 0; index1 < index2; ++index1)
		//	{
		//		tempSum = numbers[index1] + numbers[index2];
		//		if (tempSum == target)
		//		{
		//			return { index1 + 1,index2 + 1 };
		//		}
		//	}
		//}

		//tempSum = numbers[index1] + numbers[index2];
		//if (tempSum == target)
		//{
		//	return { index1 + 1,index2 + 1 };
		//}

		//// two pointers 13/25 ��һ����������� ����С����������������ĳ������������ô�ʹ�����м����ֵ
		//// 2024-05-21 3PM BenjaminH @MZ Tech
		//while (index1 < index2 && index2 < numbers.size())
		//{
		//	if (index1 + 1 == index2)
		//	{
		//		++index2;
		//	}
		//	else if (index2 + 1 >= numbers.size())
		//	{
		//		++index1;
		//	}
		//	else if (numbers[index1 + 1] - numbers[index1] <= numbers[index2 + 1] - numbers[index2])
		//	{
		//		++index1;
		//	}
		//	else if (index2 + 1 < numbers.size())
		//	{
		//		++index2;
		//	}
		//	tempSum = numbers[index1] + numbers[index2];
		//	if (tempSum == target)
		//	{
		//		return { index1 + 1,index2 + 1 };
		//	}
		//}

		//This is the right 2-pointers-way
		int index1 = 0, index2 = numbers.size() - 1;
		int tempSum = 0;
		while (index1 != index2)
		{
			if (numbers[index1] + numbers[index2] == target)
			{
				return { index1 + 1,index2 + 1 };
			}
			else if (numbers[index1] + numbers[index2] > target)
			{
				--index2;
			}
			else
			{
				++index1;
			}
		}

		cout << "Wrong Answer";
		return { index1 ,index2 };
	}
};