/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-18.cpp
* Date:2022-04-26 00:09:05
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (nullptr == head) {
            return nullptr;
        }
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *pre = temp;
        while (nullptr != pre->next) {
            if (pre->next->val == val) {
                ListNode *del = pre->next;
                pre->next = del->next;
                // delete del; /* 应该有这条语句 */
                break;
            }
            pre = pre->next;
        }
        head = temp->next;
        delete temp;
        return head;
    }
};