/*
  ����������ĸ��ڵ� root ��һ����ʾĿ��͵����� targetSum ���жϸ������Ƿ���� ���ڵ㵽Ҷ�ӽڵ� ��·��������·�������нڵ�ֵ��ӵ���Ŀ��� targetSum ��������ڣ����� true �����򣬷��� false ��

Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
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