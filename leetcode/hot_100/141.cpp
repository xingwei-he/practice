/**************************************
* He Xingwei, All Rights Reserved.
* Filename:141.cpp
* Date:2022-04-21 17:56:07
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head) {
            return false;
        }
        ListNode *p1 = head, *p2 = head;
        bool has_circle = false;
        while (p2->next != nullptr && p2->next->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) {
                has_circle = true;
                break;
            }
        }
        return has_circle;
    }
};