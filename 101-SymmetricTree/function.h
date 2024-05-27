//给你一棵二叉树，查看其是否轴对称

#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
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
	bool isRealSymmetric(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == nullptr && root2 == nullptr)
		{
			return true;
		}
		else if(root1!=nullptr && root2!=nullptr)
		{
			if (root1->val != root2->val)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		if (isRealSymmetric(root1->left, root2->right) && isRealSymmetric(root1->right, root2->left))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
		{
			//
			return true;
		}
		else if (root->left == nullptr && root->right == nullptr)
		{
			return true;
		}
		else if (root->left != nullptr && root->right != nullptr)
		{
			if (root->left->val != root->right->val)
			{
				return false;
			}
		}
		else
		{
			return false;
		}

		//
		if (isRealSymmetric(root->left,root->right))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};