/*
给定一个二叉树：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。

初始状态下，所有 next 指针都被设置为 NULL 。
*/

#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    stack<Node*> pNodeStack;
    //注意这里的&
    void process(Node* &last, Node* &p,Node* & nextStart) {
        if (last != nullptr)
        {
            last->next = p;
        }
        if (nextStart == nullptr)
        {
            nextStart = p;
        }
        last = p;
    }
    Node* connect(Node* root) {
        if (root == nullptr)
        {
            return root;
        }
        Node* start = root;
        while (start != nullptr)
        {
            Node* last = nullptr, *nextStart = nullptr;
            for (Node* p = start; p != nullptr; p = p->next)
            {
                if (p->left != nullptr)
                {
                    process(last,p->left,nextStart);
                }
                if (p->right != nullptr)
                {
                    process(last, p->right, nextStart);
                }
            }
            start = nextStart;
        }
        return root;
	}
};