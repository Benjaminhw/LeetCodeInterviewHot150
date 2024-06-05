/*
����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
*/

#pragma once
#include <iostream>
#include <vector>
#include <limits.h>

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
	long pre = LONG_MIN;
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}
		bool a = isValidBST(root->left);
		bool c = pre < root->val;
		pre = root->val;
		bool b = isValidBST(root->right);
		return a && b && c;
	}
};