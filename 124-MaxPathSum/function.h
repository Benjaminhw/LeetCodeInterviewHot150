/*
�������е� ·�� ������Ϊһ���ڵ����У�������ÿ�����ڽڵ�֮�䶼����һ���ߡ�
ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ㡣

·���� ��·���и��ڵ�ֵ���ܺ͡�

����һ���������ĸ��ڵ� root �������� ���·���� ��
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

//��Ҷ�ӽ�㲻��ȡ���ֵ�������·���ͣ�����һ��֧·ֻ����һ��

class Solution {
private:
	//�����������ͳ��ʵ��·�������ֵ -����Ҫͳ�Ƶ������
	int maxSum = INT_MIN;

public:
	//����������ص�ֵ��������·�ﹱ�׸�������� -����Ҫ�ݹ�������
	int maxGain(TreeNode* node){
		if (node == nullptr)
		{
			return 0;
		}
		//С��0�Ĳ��ɿ���
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