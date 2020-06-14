#pragma once
#include "basic_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* tail = result;

        int r = 0;
        int s = 0;
        while (l1 != nullptr || l2 != nullptr) {
            //sum 
            int left = (nullptr != l1) ? l1->val : 0;
            int right = (nullptr != l2) ? l2->val : 0;
            s = left + right + r;
            if (s >= 10) {
                r = 1;
                s -= 10;
            }
            else {
                r = 0;
            }
            //new node for result
            ListNode* p = new ListNode(s);
            if (result == nullptr) {
                result = p;
                tail = result;
            }
            else {
                tail->next = p;
                tail = tail->next;
            }

            //next node
            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (r != 0)
        {
            tail->next = new ListNode(r);
        }

        return result;
    }
};