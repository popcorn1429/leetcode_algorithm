#ifndef __leetcode_algorithm_86_h__
#define __leetcode_algorithm_86_h__
/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 */

#include "basic_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lowerList = NULL;
        ListNode *lowerNode = NULL;
        ListNode *higherList = NULL;
        ListNode *higherNode = NULL;

        while (head != nullptr)
        {
            ListNode *curNode = head;
            head = curNode->next;
            if (curNode->val < x)
            {
                addNode(lowerList, lowerNode, curNode);
            }
            else
            {
                addNode(higherList, higherNode, curNode);
            }
        }

        if (lowerList != nullptr)
        {
            lowerNode->next = higherList;
        }
        else
        {
            lowerList = higherList;
        }
        return lowerList;
    }

    void addNode(ListNode *&list, ListNode *&tail, ListNode *newNode)
    {
        if (tail == nullptr)
        {
            list = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
        tail->next = nullptr;
    }
};


#endif /*__leetcode_algorithm_86_h__*/