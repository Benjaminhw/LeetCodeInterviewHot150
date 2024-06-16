/*
����������ĸ���� root �����㽫��չ��Ϊһ��������

չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
չ����ĵ�����Ӧ��������� ������� ˳����ͬ��
*/

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
	TreeNode* ans = new TreeNode(-1);
	void preorderMake(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		TreeNode* tempNode = new TreeNode(root->val);
		ans->right = tempNode;
		ans = ans->right;
		preorderMake(root->left);
		preorderMake(root->right);
	}

	void flatten(TreeNode* root) {
		if (root == nullptr)
		{
			return;
		}
		auto ansCopy = ans;
		preorderMake(root);
		root->left = nullptr;
		root->right = ansCopy->right->right;
	}
};