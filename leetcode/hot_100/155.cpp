/**************************************
* He Xingwei, All Rights Reserved.
* Filename:155.cpp
* Date:2022-05-03 15:11:23
* Description:
**************************************/

#include <iostream>

using namespace std;

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        _data.push(val);
        if (_min_stack.empty()) {
            _min_stack.push(val);
        } else {
            if (_min_stack.top() < val) {
                _min_stack.push(_min_stack.top());
            } else {
                _min_stack.push(val);
            }
        }
    }
    
    void pop() {
        if (_data.empty()) {
            return;
        }
        _data.pop();
        _min_stack.pop();
    }
    
    int top() {
        return _data.top();
    }
    
    int getMin() {
        return _min_stack.top();
    }
private:
    stack<int> _data; // 存储真实数据
    stack<int> _min_stack; // 存储最小值
};