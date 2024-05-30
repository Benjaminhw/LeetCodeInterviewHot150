/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。
*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

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
	int result = INT_MAX;
	int pre = INT_MIN;

	int getMinimumDifference(TreeNode* root)
	{
		if (root == nullptr)
		{
			return result;
		}

		getMinimumDifference(root->left);

		if (pre == INT_MIN)
		{
			pre = root->val;
		}
		else
		{
			result = min(result, abs(pre - root->val));
			pre = root->val;
		}

		getMinimumDifference(root->right);

		return result;
	}
};