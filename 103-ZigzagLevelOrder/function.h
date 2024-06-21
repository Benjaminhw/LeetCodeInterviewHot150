#pragma once
#include <iostream>
#include <vector>

using namespace std;

//我的评价是reverse秒了 可以直接用上一题
class Solution {
public:
	int theLevel = 0;
	vector<vector<int>> answers; //改成这个不必讨论初值

	void levelThrough(TreeNode* root, int level)//不用引用传入可以保证层数一致性
	{
		//前中后序遍历似乎都可以,只要先左后右
		if (root == nullptr)
		{
			return;
		}
		if (answers.size() <= level)
		{
			vector<int> tempVector;
			tempVector.emplace_back(root->val);
			answers.emplace_back(tempVector);
		}
		else
		{
			answers[level].emplace_back(root->val);
		}
		levelThrough(root->left, level + 1);
		levelThrough(root->right, level + 1);
		return;
	}

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		levelThrough(root, theLevel);
		bool tempFlag = false;
		for (int i = 0; i < answers.size(); ++i)
		{
			if (tempFlag)
			{
				tempFlag = false;
				reverse(answers[i].begin(), answers[i].end());
			}
			else
			{
				tempFlag = true;
			}
		}
		return answers;
	}
};