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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int size = 0;
		auto realHead = head;
		ListNode* pre = new ListNode(-1);
		pre->next = head;
		auto fakeHead = pre;
		if (head == nullptr)
		{
			return head;
		}
		while (head != nullptr)
		{
			head = head->next;
			++size;
		}
		if (size == 1)
		{
			return nullptr;
		}
		int toDelete = size - n;

		int i = 0;
		head = realHead;
		while (head != nullptr)
		{
			if (i == toDelete)
			{
				pre->next = head->next;
			}
			pre = head;
			head = head->next;
			++i;
		}
		return fakeHead->next;
	}
};