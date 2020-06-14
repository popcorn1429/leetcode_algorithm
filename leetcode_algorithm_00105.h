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
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        if (preorder.size() != inorder.size()) return nullptr;

        int pos = 0;
        return buildTree(preorder, pos, inorder, 0, inorder.size());
    }

    TreeNode *buildTree(vector<int> &preorder, int &pos, vector<int> &inorder, int from, int to) {
        if (to - from <= 0) return nullptr;
        auto cur = new TreeNode(preorder[pos]);
        ++pos;
        int i = locate(inorder, from, to, cur->val);
        if (i == to) return cur;
        cur->left = buildTree(preorder, pos, inorder, from, i);
        cur->right = buildTree(preorder, pos, inorder, i + 1, to);
        return cur;
    }

    int locate(vector<int> &inorder, int from, int to, int v) {
        for (int i = from; i < to; ++i) {
            if (inorder[i] == v) return i;
        }
        return to;
    }
};