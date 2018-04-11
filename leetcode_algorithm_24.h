#ifndef __leetcode_algorithm_24_h__
#define __leetcode_algorithm_24_h__

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (nullptr == head)
            return nullptr;

        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = head->next;

        while (first != nullptr && second != nullptr) {
            if (prev != nullptr) {
                prev->next = second;
            }
            else {
                head = second;
            }
            first->next = second->next;
            second->next = first;

            prev = first;
            first = prev->next;
            second = (nullptr == first) ? nullptr : first->next;
        }

        return head;
    }
};
#endif