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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || inorder.size() != postorder.size()) return nullptr;

        return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size());

    }

    TreeNode *buildTree(vector<int> &postorder, int offset, int i, vector<int> &inorder, int from, int to) {
        if (to - from <= 0) return nullptr;

        auto cur = new TreeNode(postorder[offset + i]);
        int pos = locate(inorder, from, to, cur->val);
        cur->left = buildTree(postorder, offset, pos - from - 1, inorder, from, pos);
        cur->right = buildTree(postorder, offset + pos - from, to - pos - 2, inorder, pos + 1, to);
        return cur;
    }

    int locate(vector<int> &inorder, int from, int to, int v) {
        for (int i = from; i < to; ++i) {
            if (inorder[i] == v) return i;
        }
        return to;
    }
};