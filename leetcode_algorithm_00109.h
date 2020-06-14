#pragma once
#include "basic_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        convertListToVector(head, nums);

        return convertVectorToTree(nums, 0, nums.size());
    }

    void convertListToVector(ListNode *head, vector<int> &nums) {
        ListNode *cur = head;
        while (nullptr != cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
    }

    TreeNode *convertVectorToTree(vector<int> &nums, int from, int to) {
        if (to <= from) return nullptr;
        int mid = (from + to) / 2;
        auto root = new TreeNode(nums[mid]);

        root->left = convertVectorToTree(nums, from, mid);
        root->right = convertVectorToTree(nums, mid + 1, to);
        return root;
    }
};