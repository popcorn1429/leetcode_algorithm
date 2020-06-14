#pragma once
#include "basic_headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        midorder(root, output);
        return output;
    }

    void midorder(TreeNode *root, vector<int> &output) {
        if (nullptr == root) return;
        midorder(root->left, output);
        output.push_back(root->val);
        midorder(root->right, output);
    }
};