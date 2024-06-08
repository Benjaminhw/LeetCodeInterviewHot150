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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* p = new ListNode(-1),*plusHead = p;
		auto q = head;
		if (q->val != q->next->val)
		{
			p->next = q;
			p = p->next;
		}
		//条件其实是三个node都不一样，或是结尾的2个node不一样，我们需要留住的是第二个node也就是q->next;
		while (q != nullptr && q->next != nullptr)
		{
			if (q->val != q->next->val && (q->next->next == nullptr||(q->next->next->val != q->next->val) ))
			{
				p->next = q->next;
				p = p->next;
			}
			q = q->next;
		}
		p->next = nullptr;
		return plusHead->next;
	}
};