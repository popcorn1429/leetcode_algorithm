#pragma once
#include "basic_headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (nullptr == root) return;
        leftisize(root);
        rightisize(root);
    }

    TreeNode *leftisize(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr)
            return root;

        if (root->left == nullptr) {
            TreeNode *end = leftisize(root->right);
            root->left = root->right;
            root->right = nullptr;
            return end;
        }

        if (root->right == nullptr) {
            TreeNode *end = leftisize(root->left);
            return end;
        }

        TreeNode *leftend = leftisize(root->left);
        TreeNode *end = leftisize(root->right);
        leftend->left = root->right;
        root->right = nullptr;
        return end;
    }

    void rightisize(TreeNode *root) {
        TreeNode *cur = root;
        while (cur != nullptr) {
            cur->right = cur->left;
            cur->left = nullptr;
            cur = cur->right;
        }
    }
};