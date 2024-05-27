/*
����һ�� ��ȫ������ �ĸ��ڵ� root ����������Ľڵ������

��ȫ������ �Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ������ﵽ���ֵ��
����������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣬��ò���� 1~ 2h ���ڵ㡣*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		return (countNodes(root->left) + countNodes(root->right)) + 1; //���1��ָ���Լ�
	}
};