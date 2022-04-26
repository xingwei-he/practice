/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-22.cpp
* Date:2022-04-26 23:55:30
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p1 = head, *p2 = head; // p1慢，p2快
        for (int i = 0; i < k; i++) {
            p2 = p2->next;
        }
        while (nullptr != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};