/*
������Ʋ�ʵ��һ������  LRU (�������ʹ��) ���� Լ�������ݽṹ��
ʵ�� LRUCache �ࣺ
LRUCache(int capacity) �� ������ ��Ϊ���� capacity ��ʼ�� LRU ����
int get(int key) ����ؼ��� key �����ڻ����У��򷵻عؼ��ֵ�ֵ�����򷵻� -1 ��
void put(int key, int value) ����ؼ��� key �Ѿ����ڣ�����������ֵ value ��
��������ڣ����򻺴��в������ key-value ���������������¹ؼ����������� capacity ��
��Ӧ�� ��� ���δʹ�õĹؼ��֡�
���� get �� put ������ O(1) ��ƽ��ʱ�临�Ӷ����С�
*/

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>

using namespace std;

struct DLinkedNode {
	int key, value;
	DLinkedNode* prev;
	DLinkedNode* next;
	DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
	DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
	//// 19/22 ����
	//public:
	//	int theCapacity;
	//	unordered_map<int, int> LRU;
	//	unordered_map<int, int> data;
	//
	//	void LRUAddNoRepeat(int target)
	//	{
	//		if (LRU.empty())
	//		{
	//			LRU[0] = target;
	//			return;
	//		}
	//		for (int i = LRU.size(); i > 0; --i)
	//		{
	//			LRU[i] = LRU[i - 1];
	//		}
	//		if (LRU.size() > theCapacity)
	//		{
	//			LRU.erase(LRU.size() - 1);
	//		}
	//		LRU[0] = target;
	//	}
	//
	//	void LRUAddRepeat(int target)
	//	{
	//		bool flag = false;
	//		for (int i = LRU.size() - 1; i >= 0; --i)
	//		{
	//			if (LRU[i] == target)
	//			{
	//				flag = true;
	//			}
	//			if (flag)
	//			{
	//				if (i == 0)
	//				{
	//					break;
	//				}
	//				LRU[i] = LRU[i - 1];
	//			}
	//		}
	//		LRU[0] = target;
	//	}
	//
	//	LRUCache(int capacity) {
	//		theCapacity = capacity;
	//	}
	//
	//	int get(int key) {
	//		if (data.find(key) == data.end())
	//		{
	//			return -1;
	//		}
	//		else
	//		{
	//			LRUAddRepeat(key);
	//			return data[key];
	//		}
	//	}
	//
	//	void put(int key, int value) {
	//		if (data.find(key) == data.end())
	//		{
	//			if (data.size() >= theCapacity)
	//			{
	//				data.erase(LRU[theCapacity - 1]);
	//				data[key] = value;
	//				LRUAddNoRepeat(key);
	//			}
	//			else
	//			{
	//				data[key] = value;
	//				LRUAddNoRepeat(key);
	//			}
	//		}
	//		else
	//		{
	//			data[key] = value;
	//			LRUAddRepeat(key);
	//		}
	//	}
private:
	unordered_map<int, DLinkedNode*> cache;
	DLinkedNode* head;
	DLinkedNode* tail;
	int size;
	int capacity;

public:
	LRUCache(int _capacity) : capacity(_capacity), size(0) {
		// ʹ��αͷ����αβ���ڵ�
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (!cache.count(key)) {
			return -1;
		}
		// ��� key ���ڣ���ͨ����ϣ��λ�����Ƶ�ͷ��
		DLinkedNode* node = cache[key];
		moveToHead(node);
		return node->value;
	}

	void put(int key, int value) {
		if (!cache.count(key)) {
			// ��� key �����ڣ�����һ���µĽڵ�
			DLinkedNode* node = new DLinkedNode(key, value);
			// ��ӽ���ϣ��
			cache[key] = node;
			// �����˫�������ͷ��
			addToHead(node);
			++size;
			if (size > capacity) {
				// �������������ɾ��˫�������β���ڵ�
				DLinkedNode* removed = removeTail();
				// ɾ����ϣ���ж�Ӧ����
				cache.erase(removed->key);
				// ��ֹ�ڴ�й©
				delete removed;
				--size;
			}
		}
		else {
			// ��� key ���ڣ���ͨ����ϣ��λ�����޸� value�����Ƶ�ͷ��
			DLinkedNode* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
	}

	void addToHead(DLinkedNode* node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}

	void removeNode(DLinkedNode* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	void moveToHead(DLinkedNode* node) {
		removeNode(node);
		addToHead(node);
	}

	DLinkedNode* removeTail() {
		DLinkedNode* node = tail->prev;
		removeNode(node);
		return node;
	}
};
