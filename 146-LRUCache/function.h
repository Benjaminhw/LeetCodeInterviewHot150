/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，
则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
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
	//// 19/22 哈哈
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
		// 使用伪头部和伪尾部节点
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (!cache.count(key)) {
			return -1;
		}
		// 如果 key 存在，先通过哈希表定位，再移到头部
		DLinkedNode* node = cache[key];
		moveToHead(node);
		return node->value;
	}

	void put(int key, int value) {
		if (!cache.count(key)) {
			// 如果 key 不存在，创建一个新的节点
			DLinkedNode* node = new DLinkedNode(key, value);
			// 添加进哈希表
			cache[key] = node;
			// 添加至双向链表的头部
			addToHead(node);
			++size;
			if (size > capacity) {
				// 如果超出容量，删除双向链表的尾部节点
				DLinkedNode* removed = removeTail();
				// 删除哈希表中对应的项
				cache.erase(removed->key);
				// 防止内存泄漏
				delete removed;
				--size;
			}
		}
		else {
			// 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
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
