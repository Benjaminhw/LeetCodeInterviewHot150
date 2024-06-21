/*
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。
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

//从叶子结点不断取最大值来求最大路径和，搞清一条支路只能走一次

class Solution {
private:
	//这个变量用来统计实际路径的最大值 -我们要统计的是这个
	int maxSum = INT_MIN;

public:
	//这个函数返回的值是两条分路里贡献更大的那条 -我们要递归的是这个
	int maxGain(TreeNode* node){
		if (node == nullptr)
		{
			return 0;
		}
		//小于0的不可考虑
		int maxGainLeft = max(maxGain(node->left),0);
		int maxGainRight = max(maxGain(node->right),0);

		//compare
		int tempPathSum = node->val + maxGainLeft + maxGainRight;
		if (tempPathSum > maxSum)
		{
			maxSum = tempPathSum;
		}

		return node->val + max(maxGainLeft, maxGainRight);
	}

	int maxPathSum(TreeNode* root) {
		maxGain(root);
		return maxSum;
	}
};