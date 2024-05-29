/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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
	//ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	//	//ListNode* currentNode1 = list1, * currentNode2 = list2, * result = nullptr, * resultCurrentNode = nullptr;
	//	//if (list1 == nullptr && list2 == nullptr)
	//	//{
	//	//	return nullptr;
	//	//}
	//	//else if(list1 != nullptr && list2 != nullptr)
	//	//{
	//	//	if (list1->val < list2->val)
	//	//	{
	//	//		result = new ListNode(currentNode1->val);
	//	//		currentNode1 = currentNode1->next;
	//	//	}
	//	//	else
	//	//	{
	//	//		result = new ListNode(currentNode2->val);
	//	//		currentNode2 = currentNode2->next;
	//	//	}
	//	//}
	//	//else
	//	//{
	//	//	if (list1 == nullptr)
	//	//	{
	//	//		result = new ListNode(currentNode2->val);
	//	//		currentNode2 = currentNode2->next;
	//	//	}
	//	//	else
	//	//	{
	//	//		result = new ListNode(currentNode1->val);
	//	//		currentNode1 = currentNode1->next;
	//	//	}
	//	//}
	//	//result->next = resultCurrentNode;
	//	//while (currentNode1 != nullptr && currentNode2 != nullptr)
	//	//{
	//	//	int a = currentNode1->val, b = currentNode2->val;
	//	//	if (currentNode1->val < currentNode2->val)
	//	//	{
	//	//		resultCurrentNode = new ListNode(currentNode1->val);
	//	//		resultCurrentNode = resultCurrentNode->next;
	//	//		currentNode1 = currentNode1->next;
	//	//	}
	//	//	else
	//	//	{
	//	//		resultCurrentNode = new ListNode(currentNode2->val);
	//	//		resultCurrentNode = resultCurrentNode->next;
	//	//		currentNode2 = currentNode2->next;
	//	//	}
	//	//}
	//	////Merge the left.
	//	//if (currentNode1 != nullptr)
	//	//{
	//	//	while (currentNode1 != nullptr)
	//	//	{
	//	//		resultCurrentNode = new ListNode(currentNode1->val);
	//	//		resultCurrentNode = resultCurrentNode->next;
	//	//		currentNode1 = currentNode1->next;
	//	//	}
	//	//}
	//	//else if (currentNode2 != nullptr)
	//	//{
	//	//	while (currentNode2 != nullptr)
	//	//	{
	//	//		resultCurrentNode = new ListNode(currentNode2->val);
	//	//		resultCurrentNode = resultCurrentNode->next;
	//	//		currentNode2 = currentNode2->next;
	//	//	}
	//	//}
	//	//return result;
	//	
	//}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* result = nullptr, * currentNode = nullptr;
		if (list1 == nullptr && list2 == nullptr)
		{
			return nullptr;
		}
		else if (list1 == nullptr)
		{
			return list2;
		}
		else if (list2 == nullptr)
		{
			return list1;
		}
		else
		{
			//bool flag = false;
			//if (list1->val < list2->val)
			//{
			//	result = new ListNode(list1->val);
			//	list1 = list1->next;
			//}
			//else
			//{
			//	result = new ListNode(list2->val);
			//	list2 = list2->next;
			//}
			//currentNode = result;
			//while (list1 != nullptr && list2 != nullptr)
			//{
			//	if (list1->val < list2->val)
			//	{
			//		currentNode->next = new ListNode(list1->val);
			//		currentNode = currentNode->next;
			//		list1 = list1->next;
			//	}
			//	else
			//	{
			//		currentNode->next = new ListNode(list2->val);
			//		currentNode = currentNode->next;
			//		list2 = list2->next;
			//	}
			//}
			//if (list1 != nullptr)
			//{
			//	currentNode->next = list1;
			//}
			//else
			//{
			//	currentNode->next = list2;
			//}

			if (list1->val < list2->val)
			{
				result = list1;
				list1 = list1->next;
			}
			else
			{
				result = list2;
				list2 = list2->next;
			}
			currentNode = result;

			while (list1 != nullptr)
			{
				if (list2 == nullptr)
				{
					currentNode->next = list1;
					break;
				}
				else
				{
					if (list1->val < list2->val)
					{
						currentNode->next = list1;
						list1 = list1->next;
						currentNode = currentNode->next;
					}
					else
					{
						currentNode->next = list2;
						list2 = list2->next;
						currentNode = currentNode->next;
					}
				}
			}
			if (list2 != nullptr)
			{
				currentNode->next = list2;
			}
		}
		return result;
	}
};