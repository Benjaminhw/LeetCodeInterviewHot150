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
	int theLevel = 0;
	vector<vector<int>> answers; //�ĳ�����������۳�ֵ

	void levelThrough(TreeNode* root, int level)//�������ô�����Ա�֤����һ����
	{
		//ǰ�к�������ƺ�������,ֻҪ�������
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

	vector<vector<int>> levelOrder(TreeNode* root) {
		levelThrough(root, theLevel);
		return answers;
	}
};