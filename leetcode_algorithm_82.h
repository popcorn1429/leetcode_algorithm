#ifndef __leetcode_algorithm_82_h__
#define __leetcode_algorithm_82_h__

#include "basic_headers.h"

struct ListNode {
    int       val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode *prev_dup_node = nullptr;
        ListNode *first_dup_node = nullptr;
        ListNode *last_dup_node = nullptr;

        ListNode *cur_node = head;
        while (cur_node != nullptr) {
            if (cur_node->next != nullptr && cur_node->val == cur_node->next->val) {
                if (first_dup_node == nullptr) {
                    first_dup_node = cur_node;
                }
                last_dup_node = cur_node->next;
                cur_node = cur_node->next;
            }
            else {  // cur_node->next is nullptr, or cur_node->val != cur_node->next->val
                if (first_dup_node != nullptr) { //range [first_dup_node, last_dup_node] exists
                    if (prev_dup_node != nullptr) {
                        //cut range [first_dup_node, last_dup_node] off
                        prev_dup_node->next = last_dup_node->next;
                        cur_node = last_dup_node->next;
                        //delete nodes of range [first_dup_node, last_dup_node]
                        deleteNodes(first_dup_node, last_dup_node);
                        first_dup_node = nullptr;
                        last_dup_node = nullptr;
                    }
                    else {
                        cur_node = last_dup_node->next;
                        if (first_dup_node == head) {
                            head = cur_node;
                        }
                        deleteNodes(first_dup_node, last_dup_node);
                        first_dup_node = nullptr;
                        last_dup_node = nullptr;
                    }
                }
                else {  //no duplicate range now
                    prev_dup_node = cur_node;
                    cur_node = cur_node->next;
                }
            }
        }
        return head;
    }

    int deleteNodes(ListNode *first, ListNode *last) {
        int cnt = 0;
        ListNode *cur_node = first;
        while (first != last) {
            first = first->next;
            delete cur_node;
            cur_node = first;
            ++cnt;
        }

        delete first;
        return cnt + 1;
    }

    ListNode *generateList(const vector<int> &nums) {
        if (nums.empty())
            return nullptr;

        ListNode *cur_node = nullptr;
        ListNode *next_node = nullptr;
        for (vector<int>::const_reverse_iterator itr = nums.rbegin(); itr != nums.rend(); ++itr) {
            cur_node = new ListNode(*itr);
            cur_node->next = next_node;
            next_node = cur_node;
        }

        return cur_node;
    }
};

ostream &operator<<(ostream &o, const ListNode *head) {
    const ListNode *cur_node = head;
    o << "list is { ";
    while (cur_node != nullptr) {
        o << cur_node->val << " -> ";
        cur_node = cur_node->next;
    }
    o << "nullptr } ." << endl;
    return o;
}

#endif /*__leetcode_algorithm_82_h__*/
