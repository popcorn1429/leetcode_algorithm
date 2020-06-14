#pragma once
#include "basic_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev = nullptr;
        if (m > 1) {
            prev = head;
            for (int i = 2; i < m; ++i) {
                prev = prev->next;
            }
        }

        ListNode *reverse_head = (prev == nullptr) ? head : prev->next;
        ListNode *reverse_tail = reverse_head;

        ListNode *p = reverse_head;
        ListNode *q = p->next;
        for (int i = m; i < n; ++i) {
            p = q;
            q = q->next;
            p->next = reverse_head;
            reverse_head = p;
        }
        if (prev != nullptr) prev->next = reverse_head;
        reverse_tail->next = q;

        return (m == 1) ? reverse_head : head;
    }
};