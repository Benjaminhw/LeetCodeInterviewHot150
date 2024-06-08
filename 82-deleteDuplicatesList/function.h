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
		//������ʵ������node����һ�������ǽ�β��2��node��һ����������Ҫ��ס���ǵڶ���nodeҲ����q->next;
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