#ifndef __leetcode_algorithm_00617_h__
#define __leetcode_algorithm_00617_h__
#include <cstddef>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    enum class ChildPos {
        Left,
        Right
    };

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = NULL;
        if (t1 != NULL || t2 != NULL) {
            int sum = (NULL != t1 ? t1->val : 0) + (NULL != t2 ? t2->val : 0);
            root = new TreeNode(sum);
            mergeNode((NULL != t1 ? t1->left : NULL), (NULL != t2 ? t2->left : NULL), root, ChildPos::Left);
            mergeNode((NULL != t1 ? t1->right : NULL), (NULL != t2 ? t2->right : NULL), root, ChildPos::Right);
        }
        return root;
    }

    void mergeNode(TreeNode* node1, TreeNode* node2, TreeNode* parent, ChildPos pos) {
        if (node1 == NULL && node2 == NULL) {
            if (pos == ChildPos::Left) parent->left = NULL;
            else parent->right = NULL;

            return;
        }

        int sum = (NULL != node1 ? node1->val : 0) + (NULL != node2 ? node2->val : 0);
        TreeNode* node = new TreeNode(sum);
        if (pos == ChildPos::Left) parent->left = node;
        else parent->right = node;

        mergeNode((NULL != node1 ? node1->left : NULL), (NULL != node2 ? node2->left : NULL), node, ChildPos::Left);
        mergeNode((NULL != node1 ? node1->right : NULL), (NULL != node2 ? node2->right : NULL), node, ChildPos::Right);
    }

};
#endif // !__leetcode_algorithm_617_h__
