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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> route;
        toLeaf(root, route, 0, 0, sum, result);
        return result;
    }

    void toLeaf(TreeNode *cur, vector<int> &route, int pos, int total, const int sum, vector<vector<int>> &result) {
        if (cur == nullptr) return;

        total += cur->val;
        if (route.size() <= pos) route.push_back(cur->val);
        else route[pos] = cur->val;
        ++pos;

        if (cur->left == nullptr && cur->right == nullptr) {
            if (total == sum) {
                vector<int> temp(pos, 0);
                for (int i = 0; i < pos; ++i) {
                    temp[i] = route[i];
                }
                result.push_back(temp);
            }
            return;
        }


        toLeaf(cur->left, route, pos, total, sum, result);
        toLeaf(cur->right, route, pos, total, sum, result);
    }
};