#ifndef __leetcode_algorithm_00019_h__
#define __leetcode_algorithm_00019_h__


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p_end = head;
        for (int i = 0; i < n; ++i)
            p_end = p_end->next;

        if (nullptr == p_end) {
            ListNode* remove_node = head;
            head = head->next;
            delete remove_node;
            return head;
        }
            

        ListNode* p_removeNode = head->next;
        ListNode* p_prevRemove = head;
        p_end = p_end->next;

        while (p_end != nullptr) {
            p_end = p_end->next;
            p_prevRemove = p_prevRemove->next;
            p_removeNode = p_removeNode->next;
        }

        p_prevRemove->next = p_removeNode->next;
        delete p_removeNode;
        p_removeNode = nullptr;
        return head;
    }
};

#endif
