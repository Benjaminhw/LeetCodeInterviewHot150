/*
���������������� preorder �� inorder ������ preorder �Ƕ���������������� inorder ��ͬһ����������������빹�����������������ڵ㡣
*/

/*
��������һ�������ԣ�ǰ���������ʽ����

[ ���ڵ�, [��������ǰ��������], [��������ǰ��������] ]

�����ڵ�����ǰ������еĵ�һ���ڵ㡣�������������ʽ����

[ [������������������], ���ڵ�, [������������������] ]

*/

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
private:
	unordered_map<int, int> index;
public:
	TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
		//It's very hard to judge.
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // ǰ������еĵ�һ���ڵ���Ǹ��ڵ�
        int preorder_root = preorder_left;
        // ����������ж�λ���ڵ�
        int inorder_root = index[preorder[preorder_root]];

        // �ȰѸ��ڵ㽨������
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // �õ��������еĽڵ���Ŀ
        int size_left_subtree = inorder_root - inorder_left;
        // �ݹ�ع����������������ӵ����ڵ�
        // ��������С��� ��߽�+1 ��ʼ�� size_left_subtree����Ԫ�ؾͶ�Ӧ����������С��� ��߽� ��ʼ�� ���ڵ㶨λ-1����Ԫ��
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // �ݹ�ع����������������ӵ����ڵ�
        // ��������С��� ��߽�+1+�������ڵ���Ŀ ��ʼ�� �ұ߽硹��Ԫ�ؾͶ�Ӧ����������С��� ���ڵ㶨λ+1 �� �ұ߽硹��Ԫ��
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
	}

    //��������������
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // ��������ϣ��ͬʱͳ��һ��size
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};