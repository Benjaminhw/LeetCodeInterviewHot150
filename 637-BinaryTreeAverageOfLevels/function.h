/*
����һ���ǿն������ĸ��ڵ� root , ���������ʽ����ÿһ��ڵ��ƽ��ֵ����ʵ�ʴ���� 10-5 ���ڵĴ𰸿��Ա����ܡ�
*/

#pragma once
#include <iostream>
#include <vector>
#include <map>

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
	vector<double> results;
	vector<int> amount;
	void averageOfLevels(TreeNode* root, int i)
	{
		if (root == nullptr)
		{
			return;
		}
		if (results.size() > i)
		{
			results[i] += root->val;
			++amount[i];
		}
		else
		{
			results.push_back(root->val);
			amount.push_back(1);
		}
		averageOfLevels(root->left, i + 1);
		averageOfLevels(root->right, i + 1);
	}
	vector<double> averageOfLevels(TreeNode* root) {
		averageOfLevels(root, 0);
		for (int i = 0; i < results.size(); ++i)
		{
			results[i] = results[i] / amount[i];
		}
		return results;
	}
};