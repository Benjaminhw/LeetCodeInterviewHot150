/*
����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣

������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ���½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬�����������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��

���磬���ԭ�������� X �� Y �����ڵ㣬���� X.random --> Y ����ô�ڸ��������ж�Ӧ�������ڵ� x �� y ��ͬ���� x.random --> y ��

���ظ��������ͷ�ڵ㡣

��һ���� n ���ڵ���ɵ���������ʾ����/����е�����ÿ���ڵ���һ�� [val, random_index] ��ʾ��

val��һ����ʾ Node.val ��������
random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n-1���������ָ���κνڵ㣬��Ϊ  null ��
��Ĵ��� ֻ ����ԭ�����ͷ�ڵ� head ��Ϊ���������
*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		Node* headBackup = head;
		if (head == nullptr)
		{
			return nullptr;
		}
		unordered_map<Node*, int> node2NumberMap;//������¼ԭʼnode*��Ӧ��λ��
		unordered_map<int, Node*> number2NodeMap;//��¼����int��Ӧ�Ŀ���������Node*
		vector<int> nextVec;//˳���Ŷ�Ӧ��
		//�ȹ�һ���¼λ��
		Node* newHead = new Node(head->val);
		Node* newHeadBackup = newHead;
		node2NumberMap[head] = 0;
		number2NodeMap[0] = newHead;
		head = head->next;
		for (int i = 1; head != nullptr; ++i)
		{
			newHead->next = new Node(head->val);
			newHead = newHead->next;
			node2NumberMap[head] = i;
			number2NodeMap[i] = newHead;
			head = head->next;
		}
		head = headBackup;
		for (int i = 0; head != nullptr; ++i)
		{
			if (head->random == nullptr)
			{
				nextVec.push_back(-1);
			}
			else
			{
				nextVec.push_back(node2NumberMap[head->random]);
			}
			head = head->next;
		}
		newHead = newHeadBackup;
		for (int i = 0; newHead != nullptr; ++i)
		{
			if (nextVec[i] == -1)
			{
				newHead->random = nullptr;
			}
			else
			{
				newHead->random = number2NodeMap[nextVec[i]];
			}
			newHead = newHead->next;
		}
		return newHeadBackup;
	}
};