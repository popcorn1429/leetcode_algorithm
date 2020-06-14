#pragma once
#include "basic_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head) return false;

        const ListNode *slow = head;
        const ListNode *fast = head;
        while (nullptr != slow && nullptr != fast && nullptr != fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};