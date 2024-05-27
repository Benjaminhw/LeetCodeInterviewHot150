/*
  给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

叶子节点 是指没有子节点的节点。
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
	bool hasPathSumU(TreeNode* root, int targetSum,bool f) {
		if (root == nullptr)
		{
			if (targetSum == 0)
			{
				return true && f;
			}
			else
			{
				return false && f;
			}
		}
		else
		{
			targetSum -= root->val;
		}
		bool tempBool = (root->left == nullptr) && (root->right == nullptr);
		return hasPathSumU(root->left, targetSum, tempBool) || hasPathSumU(root->right, targetSum,tempBool);
	}
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		if (root == nullptr)
		{
			return false;
		}
		return hasPathSumU(root, targetSum, (root->left == nullptr) && (root->right == nullptr));
	}
};