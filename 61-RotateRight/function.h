/*
����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�
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
	ListNode* rotateRight(ListNode* head, int k) {
		int i = 0;
		ListNode* originalHead = head/*, * originalTail = nullptr*/;
		ListNode* ans = nullptr,* preAns = nullptr;
		while (head != nullptr)
		{
			if (head->next == nullptr)
			{
				//originalTail = head;
				head->next = originalHead;
				break;
			}
			head = head->next;
			
		}
		head = originalHead;
		while (head != nullptr)
		{
			if (i == k)
			{
				ans = head->next;
				preAns = head;
				head->next = nullptr;
				break;
			}
			head = head->next;
			++i;
		}
		return ans;
	}
};