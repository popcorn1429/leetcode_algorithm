#ifndef __leetcode_algorithm_61_h__
#define __leetcode_algorithm_61_h__


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;

        int len = 1;
        ListNode* p = head;
        while (p->next != nullptr) {
            ++len;
            p = p->next;
        }

        p->next = head; //circle

        k %= len;
        for (int i = 0; i < len - k; ++i) {
            p = p->next;
        }

        head = p->next;
        p->next = nullptr;
        return head;
    }
};

#endif