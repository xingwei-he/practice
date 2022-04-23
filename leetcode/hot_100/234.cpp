/**************************************
* He Xingwei, All Rights Reserved.
* Filename:234.cpp
* Date:2022-04-23 23:15:36
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (nullptr == head) {
            return false;
        }
        if (nullptr == head->next) {
            return true;
        }
        ListNode *temp = new ListNode();
        ListNode *p = new ListNode();
        p->next = head;
        ListNode *p1 = p, *p2 = p;
        while (nullptr != p2->next && nullptr != p2->next->next) {
            p2 = p2->next->next;
            p1 = p1->next;
            p->next = p1->next;
            p1->next = temp->next;
            temp->next = p1;
            p1 = p;
        }
        if (nullptr == p2->next) { // 偶数个节点
            p2 = temp->next;
            p1 = p->next;
        } else { // 奇数个节点
            p2 = temp->next;
            p1 = p->next->next;
        }
        bool is_palindrome = true;
        while (nullptr != p1 && nullptr != p2) {
            if (p1->val != p2->val) {
                is_palindrome = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return is_palindrome;
    }
};
