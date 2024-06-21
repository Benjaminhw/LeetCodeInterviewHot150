#pragma once
#include <iostream>
#include <vector>

using namespace std;

//�ҵ�������reverse���� ����ֱ������һ��
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