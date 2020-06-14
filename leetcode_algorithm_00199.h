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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (nullptr == root) return result;

        list<TreeNode *> currentTier;
        list<TreeNode *> nextTier;

        currentTier.push_back(root);
        while (!currentTier.empty()) {
            TreeNode *rightmost = *currentTier.rbegin();
            result.push_back(rightmost->val);
            for (auto itCur = currentTier.begin(); itCur != currentTier.end(); ++itCur) {
                if (nullptr != (*itCur)->left) nextTier.push_back((*itCur)->left);
                if (nullptr != (*itCur)->right) nextTier.push_back((*itCur)->right);
            }

            currentTier.swap(nextTier);
            nextTier.clear();
        }
        return result;
    }
};