/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
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