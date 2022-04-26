/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-52.cpp
* Date:2022-04-26 23:47:05
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        auto get_length = [](ListNode *head) ->int {
            int len = 0;
            while (nullptr != head) {
                len++;
                head = head->next;
            }
            return len;
        };
        int len1 = get_length(head1);
        int len2 = get_length(head2);
        ListNode *p1 = head1, *p2 = head2;
        if (len1 > len2) {
            for (int i = 0; i < (len1 - len2); i++) {
                p1 = p1->next;
            }
        } else {
            for (int i = 0; i < (len2 - len1); i++) {
                p2 = p2->next;
            }
        }
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};