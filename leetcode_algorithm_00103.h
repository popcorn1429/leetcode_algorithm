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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (nullptr == root) return vector<vector<int>>();
        vector<vector<int>> results;

        vector<TreeNode *> curLayer;
        vector<TreeNode *> nextLayer;
        curLayer.push_back(root);
        bool direction = false;//true = left->right, false = right->left
        while (!curLayer.empty()) {
            output(curLayer, results);

            getNextLayer(curLayer, nextLayer, direction);
            curLayer.swap(nextLayer);
            nextLayer.clear();
            direction = !direction;
        }
        return results;
    }

    void getNextLayer(vector<TreeNode *> &curLayer, vector<TreeNode *> &nextLayer, bool direction) {
        if (direction) {
            for (auto itr = curLayer.rbegin(); itr != curLayer.rend(); ++itr) {
                if (nullptr != (*itr)->left) nextLayer.push_back((*itr)->left);
                if (nullptr != (*itr)->right) nextLayer.push_back((*itr)->right);
            }
        }
        else {
            for (auto itr = curLayer.rbegin(); itr != curLayer.rend(); ++itr) {
                if (nullptr != (*itr)->right) nextLayer.push_back((*itr)->right);
                if (nullptr != (*itr)->left) nextLayer.push_back((*itr)->left);
            }
        }
    }

    void output(vector<TreeNode *> &curLayer, vector<vector<int>> &results) {
        results.push_back(vector<int>());
        for (auto itr = curLayer.begin(); itr != curLayer.end(); ++itr) {
            results[results.size() - 1].push_back((*itr)->val);
        }
    }
};