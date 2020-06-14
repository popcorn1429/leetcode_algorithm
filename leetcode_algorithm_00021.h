#pragma once
#include "basic_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                l2 = splice(head, tail, l2);
            }
            else if (l2 == nullptr) {
                l1 = splice(head, tail, l1);
            }
            else {
                if (l1->val < l2->val) {
                    l1 = splice(head, tail, l1);
                }
                else {
                    l2 = splice(head, tail, l2);
                }
            }
        }

        return head;
    }

    ListNode* splice(ListNode*& head, ListNode*& tail, ListNode* node) {
        if (node == nullptr)
            return nullptr;

        if (head == nullptr) {
            head = node;
            tail = head;
        }
        else {
            tail->next = node;
            tail = node;
        }

        node = node->next;
        return node;
    }
};