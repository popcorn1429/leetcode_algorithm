#pragma once
#include "basic_headers.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : _min(INT_MAX) {

    }

    void push(int x) {
        if (x <= _min) {
            _aux.push(_min);
            _min = x;
        }
        _aux.push(x);
    }

    void pop() {
        int i = _aux.top();
        _aux.pop();
        if (i == _min) {
            _min = _aux.top();
            _aux.pop();
        }
    }

    int top() {
        return _aux.top();
    }

    int getMin() {
        return _min;
    }
private:
    stack<int> _aux;
    int        _min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */