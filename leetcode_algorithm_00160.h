#pragma once
#include "basic_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB) return nullptr;

        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB && !(pA == nullptr && pB == nullptr))
        {
            if (pA == nullptr) pA = headB;
            if (pB == nullptr) pB = headA;
            if (pA == pB) return pA;

            pA = pA->next;
            pB = pB->next;
        }

        return (pA == pB && pA != nullptr) ? pA : nullptr;
    }
};