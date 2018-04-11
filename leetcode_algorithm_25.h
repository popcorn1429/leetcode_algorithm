#ifndef __leetcode_algorithm_25_h__
#define __leetcode_algorithm_25_h__

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (nullptr == head)
            return nullptr;

        ListNode* prev = nullptr; //node before head
        ListNode* begin = head;
        ListNode* end = travel(begin, k);
        
        ListNode* tail = (end == nullptr) ? nullptr : end->next; //node after end;
        if (end != nullptr) {
            head = end;
            while (end != nullptr) {
                reverse(prev, begin, end, tail);

                prev = begin;
                begin = tail;
                end = travel(begin, k);
                tail = (end == nullptr) ? nullptr : end->next; //node after end;
            }
        }
        
        return head;
    }

    void reverse(ListNode* prev, ListNode* begin, ListNode* end, ListNode* tail) {
        ListNode* cur = begin->next;
        if (nullptr != prev) {
            while (cur != tail) {
                ListNode* lastBegin = prev->next;
                prev->next = cur;
                begin->next = cur->next;
                cur->next = lastBegin;

                cur = begin->next;
            }
        }
        else {
            ListNode* lastBegin = begin;
            while (cur != tail) {
                begin->next = cur->next;
                cur->next = lastBegin;
                lastBegin = cur;

                cur = begin->next;
            }
        }
    }

    ListNode* travel(ListNode* begin, int k) {
        ListNode* end = begin;
        for (int i = 1; i < k; ++i) {
            if (end != nullptr)
                end = end->next;
            else
                break;
        }
        return end;
    }
};
#endif