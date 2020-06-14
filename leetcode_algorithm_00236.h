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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parents[root] = nullptr;
        findParents(root);

        set<TreeNode *> p_parents;
        TreeNode *p_parent = p;
        while (p_parent != nullptr) {
            p_parents.insert(p_parent);
            p_parent = parents[p_parent];
        }

        TreeNode *q_parent = q;
        while (q_parent != nullptr) {
            if (p_parents.find(q_parent) != p_parents.end()) return q_parent;

            q_parent = parents[q_parent];
        }
        return nullptr;
    }

    void findParents(TreeNode *node) {
        if (node == nullptr) return;
        if (node->left != nullptr) parents[node->left] = node;
        if (node->right != nullptr) parents[node->right] = node;
        findParents(node->left);
        findParents(node->right);
    }

private:
    map<TreeNode *, TreeNode *> parents;
};