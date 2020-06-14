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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (nullptr == root) return nullptr;
        if (root->val == val) return root;
        TreeNode *result = searchBST(root->left, val);
        if (nullptr != result) return result;
        return searchBST(root->right, val);
    }
};