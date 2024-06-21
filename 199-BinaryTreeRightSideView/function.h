//����һ���������� ���ڵ� root�������Լ�վ�������Ҳ࣬���մӶ������ײ���˳��
//���ش��Ҳ����ܿ����Ľڵ�ֵ��

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
	unordered_map<int, int> answers; //�ĳ�����������۳�ֵ

	void levelThrough(TreeNode* root, int level)//�������ô�����Ա�֤����һ����
	{
		//ǰ�к�������ƺ�������,ֻҪ�������
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