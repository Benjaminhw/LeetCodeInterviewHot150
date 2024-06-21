//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，
//返回从右侧所能看到的节点值。

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

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
	int theLevel = 0;
	unordered_map<int, int> answers; //改成这个不必讨论初值

	void levelThrough(TreeNode* root, int level)//不用引用传入可以保证层数一致性
	{
		//前中后序遍历似乎都可以,只要先左后右
		if (root == nullptr)
		{
			return;
		}
		levelThrough(root->left, level + 1);
		levelThrough(root->right, level + 1);
		answers[level] = root->val;
		return;
	}

	vector<int> rightSideView(TreeNode* root) {
		levelThrough(root, theLevel);
		vector<int> theAnswers;
		for (int i = 0; i < answers.size(); ++i)
		{
			theAnswers.emplace_back(answers[i]);
		}
		return theAnswers;
	}
};