/*给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵
平衡
 二叉搜索树。*/

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
	TreeNode* BuildBST(vector<int>& nums, int a, int b) {
		if (a > b)
		{
			return nullptr;
		}
		int middle = (a + b) / 2;
		TreeNode* pNode = new TreeNode;
		pNode->val = nums[middle];
		pNode->left = BuildBST(nums, a, middle - 1);
		pNode->right = BuildBST(nums, middle + 1, b);
		return pNode;
	};

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
		{
			return nullptr;
		}
		return BuildBST(nums, 0, nums.size() - 1);
	}
};