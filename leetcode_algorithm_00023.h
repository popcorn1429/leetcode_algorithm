#ifndef __leetcode_algorithm_00023_h__
#define __leetcode_algorithm_00023_h__

#include <vector>
using namespace std;

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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        auto sz = lists.size();
        while (sz > 1) {
            sz = merge(lists, sz);
        }

        return lists[0];
    }

    vector<ListNode*>::size_type merge(vector<ListNode*>& lists, vector<ListNode*>::size_type sz) {
        if (sz == 1)
            return sz;

        vector<ListNode*>::size_type i = 0;
        vector<ListNode*>::size_type j = sz - 1;
        while (i < j) {
            ListNode* merged = mergeTwoList(lists[i], lists[j]);
            lists[i] = merged;

            ++i;
            --j;
        }

        lists.resize((sz + 1) / 2);
        return lists.size();
    }

    ListNode* mergeTwoList(ListNode* first, ListNode* second) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (first != nullptr || second != nullptr)
        {
            if (first == nullptr) {
                addNode(head, tail, second);
                break;
            }
            else if (second == nullptr) {
                addNode(head, tail, first);
                break;
            }
            else {
                if (first->val < second->val) {
                    addNode(head, tail, first);
                    first = first->next;
                }
                else {
                    addNode(head, tail, second);
                    second = second->next;
                }
            }
        }

        return head;
    }

    void addNode(ListNode*& head, ListNode*& tail, ListNode* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            if (node != nullptr) {
                tail->next = node;
                tail = tail->next;
            }
        }
    }
};
#endif
