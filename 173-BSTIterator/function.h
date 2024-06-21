/*
* ʵ��һ��������������������BSTIterator ����ʾһ�����������������������BST���ĵ�������
BSTIterator(TreeNode root) ��ʼ�� BSTIterator ���һ������BST �ĸ��ڵ� root ����Ϊ
���캯����һ���ָ�����ָ��Ӧ��ʼ��Ϊһ���������� BST �е����֣��Ҹ�����С�� BST �е��κ�Ԫ�ء�
boolean hasNext() �����ָ���Ҳ�����������֣��򷵻� true �����򷵻� false ��
int next()��ָ�������ƶ���Ȼ�󷵻�ָ�봦�����֡�
ע�⣬ָ���ʼ��Ϊһ���������� BST �е����֣����Զ� next() ���״ε��ý����� BST �е���СԪ�ء�

����Լ��� next() ����������Ч�ģ�Ҳ����˵�������� next() ʱ��BST ��������������ٴ���һ����һ�����֡�
*/
#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

//��map? ������queue�ȽϺ���
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    queue<int> theNumbers;

    void buildStack(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        buildStack(root->left);
        theNumbers.push(root->val);
        buildStack(root->right);
    }
    BSTIterator(TreeNode* root) {
        buildStack(root);
    }

    int next() {
        int x = theNumbers.front();
        theNumbers.pop();
        return x;
    }

    bool hasNext() {
        return !theNumbers.empty();
    }
};
