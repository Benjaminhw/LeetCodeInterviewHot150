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
	int ans = 0;
	void goThroughEveryNode(TreeNode* cur, int number)
	{
		if (cur == nullptr)
		{
			return;
		}
		if (cur->left == nullptr && cur->right == nullptr)
		{
			ans += cur->val + number*10;
		}
		goThroughEveryNode(cur->left, cur->val + number * 10);
		goThroughEveryNode(cur->right, cur->val + number * 10);
	}
	int sumNumbers(TreeNode* root) {
		goThroughEveryNode(root, 0);
		return ans;
	}
};