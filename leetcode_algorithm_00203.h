#pragma once
#include "basic_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (nullptr != head && head->val == val) {
            head = head->next;
        }

        if (nullptr == head) return nullptr;

        ListNode *cur = head;
        ListNode *nxt = cur->next;
        while (nullptr != nxt) {
            if (nxt->val == val) {
                cur->next = nxt->next;
            }
            else {
                cur = nxt;
            }
            nxt = cur->next;
        }
        return head;
    }
};