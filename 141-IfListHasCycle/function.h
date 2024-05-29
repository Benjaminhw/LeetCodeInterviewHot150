/*����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���

�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ
����β���ӵ������е�λ�ã������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������

��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
*/

#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;


//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == nullptr)
		{
			return false;
		}
		map<ListNode*, int> tempMap;
		for (ListNode* currentNode = head; currentNode->next != nullptr; currentNode = currentNode->next)
		{
			if (tempMap.find(currentNode) != tempMap.end())
			{
				return true;
			}
			else
			{
				tempMap[currentNode] = 1;
			}
		}
		return false;
	}
};