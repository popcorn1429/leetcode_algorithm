#pragma once
#include "basic_headers.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (nullptr == root) return nullptr;

        if (root->right != nullptr) {
            root->right->next = find(root);
        }

        if (root->left != nullptr) {
            if (root->right != nullptr) {
                root->left->next = root->right;
            }
            else {
                root->left->next = find(root);
            }
        }

        connect(root->right);
        connect(root->left);
        return root;
    }

    Node *find(Node *root) {
        Node *cur = root->next;
        while (cur != nullptr) {
            if (cur->left != nullptr) return cur->left;

            if (cur->right != nullptr) return cur->right;

            cur = cur->next;
        }
        return nullptr;
    }
};