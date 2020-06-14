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
    int sumNumbers(TreeNode* root) {
        return update(root, 0);;
    }

    int update(TreeNode *root, int sum) {
        if (root == nullptr) return 0;

        sum = sum * 10 + root->val;

        if (nullptr == root->left && nullptr == root->right) {
            return sum;
        }
        else {
            return update(root->left, sum) + update(root->right, sum);
        }
    }
};