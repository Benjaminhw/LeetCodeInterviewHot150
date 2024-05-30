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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* pre = nullptr;
		ListNode* result = l1;
		bool isUpgrade = false;
		int current = 0;
		while (l1 != nullptr && l2 != nullptr)
		{
			current = l1->val + l2->val + (int)isUpgrade;
			if (current >= 10)
			{
				isUpgrade = true;
				current -= 10;
			}
			else
			{
				isUpgrade = false;
			}
			l1->val = current;
			pre = l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l2 != nullptr)
		{
			pre->next = l2;
			l1 = pre->next;
		}
		while (l1 != nullptr)
		{
			if (!isUpgrade)
			{
				break;
			}
			current = l1->val + (int)isUpgrade;
			if (current >= 10)
			{
				isUpgrade = true;
				current -= 10;
			}
			else
			{
				isUpgrade = false;
			}
			l1->val = current;
			pre = l1;
			l1 = l1->next;
		}
		if (isUpgrade)
		{
			l1 = new ListNode(1);
			pre->next = l1;
		}
		return result;
	}
};