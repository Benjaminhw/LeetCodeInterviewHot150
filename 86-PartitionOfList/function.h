#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* p = new ListNode(-1);
		ListNode* q = new ListNode(-1);
		ListNode* originalP = p, * originalQ = q;
		while (head != nullptr)
		{
			if (head->val >= x)
			{
				q->next = head;
				q = q->next;
			}
			else
			{
				p->next = head;
				p = p->next;
			}
			head = head->next;
		}
		p->next = originalQ->next;
		return originalP->next;
	}
};