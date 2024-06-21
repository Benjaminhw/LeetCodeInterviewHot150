#pragma once
#include <iostream>
#include <vector>

/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大
（一个节点也可以是它自己的祖先）。”
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

//这里的思路是用两个bool flag去做，找到两个的时候 两个flag为true，在第一个为true的分叉，记录值
//并且再把两个flag设为false
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

        //此处决定结果
        if (thisFlag && (flagA || flagB))
        {
            ans = root;
        }
        else if (flagA && flagB)
        {
            ans = root;
        }

        //此处是为了递归传递结果
        return thisFlag || flagA || flagB;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findTheFlag(root, p, q);
        return ans;
    }
};