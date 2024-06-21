#pragma once
#include <iostream>
#include <vector>

/*
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q��
����������ȱ�ʾΪһ���ڵ� x������ x �� p��q �������� x ����Ⱦ����ܴ�
��һ���ڵ�Ҳ���������Լ������ȣ�����
*/

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//�����˼·��������bool flagȥ�����ҵ�������ʱ�� ����flagΪtrue���ڵ�һ��Ϊtrue�ķֲ棬��¼ֵ
//�����ٰ�����flag��Ϊfalse
class Solution {
    TreeNode* ans = nullptr;
public:
    bool findTheFlag(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return false;
        }

        bool thisFlag = false;
        bool flagA =findTheFlag(root->left, p, q);
        bool flagB =findTheFlag(root->right, p, q);

        if (root == p)
        {
            thisFlag = true;
        }
        if (root == q)
        {
            thisFlag = true;
        }

        //�˴��������
        if (thisFlag && (flagA || flagB))
        {
            ans = root;
        }
        else if (flagA && flagB)
        {
            ans = root;
        }

        //�˴���Ϊ�˵ݹ鴫�ݽ��
        return thisFlag || flagA || flagB;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findTheFlag(root, p, q);
        return ans;
    }
};