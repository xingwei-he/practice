/**************************************
* He Xingwei, All Rights Reserved.
* Filename:160.cpp
* Date:2022-04-23 18:35:25
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int getLength(ListNode *p) {
        int len = 0;
        while (nullptr != p) {
            len++;
            p = p->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *list1, ListNode *list2) {      
        if (nullptr == list1 || nullptr == list2) {
            return nullptr;
        }
        int len1 = getLength(list1);
        int len2 = getLength(list2);
        if (len1 > len2) {
            for (int i = 0; i < (len1 - len2); i++) {
                list1 = list1->next;
            }
        } else {
            for (int i = 0; i < (len2 - len1); i++) {
                list2 = list2->next;
            }
        }
        while (list1 != list2) {
            list1 = list1->next;
            list2 = list2->next;
        }
        return list1;
    }
};