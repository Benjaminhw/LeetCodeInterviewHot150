#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//想直接用map
class Solution {
private:
    map<int, int> theMap;
    void buildMap(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        theMap[root->val] = 1;
        buildMap(root->left);
        buildMap(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        buildMap(root);
        auto x = theMap.begin();
        for (int i = 1; i < k; ++i)
        {
            ++x;
        }
        return (*x).first;
    }
};