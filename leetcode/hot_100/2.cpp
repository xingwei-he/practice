/**************************************
* He Xingwei, All Rights Reserved.
* Filename:2.cpp
* Date:2022-04-17 23:59:19
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (nullptr == l1 || nullptr == l2) {
            return nullptr;
        }
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* l = new ListNode();
        ListNode* p = l;
        int inc = 0;
        while (nullptr != p1 && nullptr != p2) {
            p->next = new ListNode();
            p = p->next;
            p->val = (p1->val + p2->val + inc) % 10;
            inc = (p1->val + p2->val + inc) / 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (nullptr != p1) {
            p->next = new ListNode();
            p = p->next;
            p->val = (p1->val + inc) % 10;
            inc = (p1->val + inc) / 10;
            p1 = p1->next;
        }
        while (nullptr != p2) {
            p->next = new ListNode();
            p = p->next;
            p->val = (p2->val + inc) % 10;
            inc = (p2->val + inc) / 10;
            p2 = p2->next;
        }
        if (inc > 0) {
            p->next = new ListNode();
            p = p->next;
            p->val = inc;
            inc = 0;
        }
        p = l->next;
        delete l;
        return p;
    }
};
