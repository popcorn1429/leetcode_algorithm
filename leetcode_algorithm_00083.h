#ifndef __leetcode_algorithm_00083_h__
#define __leetcode_algorithm_00083_h__

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = head;
        if (first == nullptr)
            return nullptr;

        ListNode* second = first->next;

        while (second != nullptr) {
            if (isEqual(first, second)) {
                first->next = second->next;
                delete second;
                second = first->next;
            }
            else {
                first = second;
                second = second->next;
            }
        }
    }

    inline bool isEqual(ListNode* first, ListNode* second) {
        return first->val == second->val;
    }
};
#endif
