/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-06.cpp
* Date:2022-04-25 23:26:03
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if (nullptr == head) {
            return res;
        }
        stack<int> stk;
        ListNode *p = head;
        while (p != nullptr) {
            stk.push(p->val);
            p = p->next;
        }
        res.reserve(stk.size());
        while (!stk.empty()) {
            res.emplace_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
