/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-24.cpp
* Date:2022-04-25 23:47:52
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        ListNode *temp = new ListNode();
        temp->next = nullptr;
        ListNode *p1 = nullptr, *p2 = head;
        while (p2 != nullptr) {
            p1 = p2;
            p2 = p2->next;
            p1->next = temp->next;
            temp->next = p1;
        }
        head = temp->next;
        delete temp;
        return head;
    }
};