/*
���㵥�����ͷָ�� head ���������� left �� right ������ left <= right ��
���㷴ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת������� ��
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		int i = 1;
		while (head != nullptr)
		{
			if (i == left)
			{

			}
		}
	}
};