#ifndef __leetcode_algorithm_100_h__
#define __leetcode_algorithm_100_h__

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (nullptr == p && nullptr == q)
            return true;

        if (p != nullptr && q != nullptr){
            if (p->val == q->val) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
        return false;
    }
};
#endif