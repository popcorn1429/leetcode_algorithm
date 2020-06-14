#pragma once
#include "basic_headers.h"

class LRUCache {
private:
    struct DoubleLinkedNode {
        DoubleLinkedNode(int key, int val) : _key(key), _value(val), _next(nullptr), _prev(nullptr) {}
        ~DoubleLinkedNode() {};

        int _key;
        int _value;
        DoubleLinkedNode *_next;
        DoubleLinkedNode *_prev;
    };

    class DoubleLinkedList {
    public:
        DoubleLinkedList() {
            _head = new DoubleLinkedNode(-1, 0);
            _tail = new DoubleLinkedNode(-1, 0);
            _head->_next = _tail;
            _tail->_prev = _head;
            _cnt = 0;
        }

        ~DoubleLinkedList() {
            DoubleLinkedNode *cur = _head;
            while (cur != nullptr) {
                DoubleLinkedNode *nxt = cur->_next;
                delete cur;
                cur = nxt;
            }
        }

        size_t size() const { return _cnt; }

        bool moveToHead(DoubleLinkedNode *node) {
            return replaceNode(node, _head);
        }

        DoubleLinkedNode *pop_back() {
            return removeNode(_tail->_prev);
        }

        bool push_front(DoubleLinkedNode *node) {
            return insertNode(node, _head);
        }

    private:
        bool insertNode(DoubleLinkedNode *node, DoubleLinkedNode *pos) {
            if (pos == _tail) return false;

            node->_next = pos->_next;
            pos->_next = node;
            node->_next->_prev = node;
            node->_prev = pos;

            ++_cnt;

            return true;
        }

        DoubleLinkedNode *removeNode(DoubleLinkedNode *node) {
            if (node == _head || node == _tail) return nullptr;

            node->_prev->_next = node->_next;
            node->_next->_prev = node->_prev;

            --_cnt;

            return node;
        }

        bool replaceNode(DoubleLinkedNode *node, DoubleLinkedNode *newPos) {
            if (newPos == _tail) return false;
            if (node == _head || node == _tail) return false;

            if (node->_prev == newPos) return true;

            if (removeNode(node) != nullptr) {
                return insertNode(node, newPos);
            }
            return false;
        }
    private:
        DoubleLinkedNode *_head;
        DoubleLinkedNode *_tail;
        size_t            _cnt;
    };

public:
    LRUCache(int capacity) {
        _indexes.clear();
        _list = new DoubleLinkedList;
        _capacity = capacity;
    }

    ~LRUCache() {
        delete _list;
    }

    int get(int key) {
        int val = -1;
        if (_indexes.count(key) != 0) {
            val = _indexes[key]->_value;
            _list->moveToHead(_indexes[key]);
        }
        return val;
    }

    void put(int key, int value) {
        if (_indexes.count(key) != 0) {
            _indexes[key]->_value = value;
            _list->moveToHead(_indexes[key]);
        }
        else {
            _indexes[key] = new DoubleLinkedNode(key, value);
            _list->push_front(_indexes[key]);
            if (_list->size() > _capacity) {
                DoubleLinkedNode *node = _list->pop_back();
                _indexes.erase(node->_key);
                delete node;
            }
        }
    }

private:
    unordered_map<int, DoubleLinkedNode *> _indexes;
    DoubleLinkedList                      *_list;
    size_t                                 _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */