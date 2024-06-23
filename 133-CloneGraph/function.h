#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
	unordered_map< Node*, Node*> original2CopyMap;
public:
	Node* findClone(Node* node)
	{
		if (original2CopyMap.find(node) != original2CopyMap.end())
		{
			return original2CopyMap[node];
		}
		
		Node* cloneNode = new Node;
		cloneNode->val = node->val;
		original2CopyMap[node] = cloneNode;
		for (auto& x : node->neighbors)
		{
			cloneNode->neighbors.emplace_back(findClone(x));
		}
		
		return cloneNode;
	}

	Node* cloneGraph(Node* node) {
		if (node == nullptr)
		{
			return nullptr;
		}
		auto x = findClone(node);
		return x;
	}
};