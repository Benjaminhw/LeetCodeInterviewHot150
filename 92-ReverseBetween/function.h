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
		if (left == right)
		{
			return head;
		}
		ListNode* OriginalHead = nullptr, * OriginalTail = nullptr, * Pre = nullptr, * Post = nullptr, * OriginalPreHead = nullptr, * OriginalPostTail = nullptr, * theVeryFirstHead = head, * theVeryLastTail = nullptr;
		while (head != nullptr)
		{
			if (head->next == nullptr)
			{
				theVeryLastTail = head;
			}
			if (i == left - 1)
			{
				Pre = head;
				OriginalPreHead = head;
				head = head->next;
			}
			else if (i == left)
			{
				OriginalHead = head;
				Pre = head;
				head = head->next;
			}
			else if (i == right)
			{
				Post = head->next;
				OriginalTail = head;
				head->next = Pre;
				head = Post;
			}
			else if (i == right + 1)
			{
				OriginalPostTail = head;
				head = head->next;
			}
			else if (i > left && i < right)
			{
				Post = head->next;
				head->next = Pre;
				Pre = head;
				head = Post;
			}
			else
			{
				head = head->next;
			}
			++i;
		}
		if (OriginalPreHead != nullptr)
		{
			OriginalPreHead->next = OriginalTail;
		}
		else
		{
			OriginalHead->next = nullptr;
		}
		if (OriginalPostTail != nullptr)
		{
			OriginalHead->next = OriginalPostTail;
		}
		else
		{
			OriginalHead->next = nullptr;
		}
		if (OriginalPreHead == nullptr)
		{
			return OriginalTail;
		}
		return theVeryFirstHead;
	}
};