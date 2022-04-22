/**************************************
* He Xingwei, All Rights Reserved.
* Filename:21.cpp
* Date:2022-04-21 18:15:18
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    	if (nullptr == list1) {
    		return list2;
    	}
    	if (nullptr == list2) {
    		return list1;
    	}
    	ListNode *temp = new ListNode();
    	ListNode *p = temp;
    	while (nullptr != list1 && nullptr != list2) {
    		if (list1->val <= list2->val) {
    			p->next = list1;
    			p = p->next;
    			list1 = list1->next;
    		} else {
    			p->next = list2;
    			p = p->next;
    			list2 = list2->next;
    		}
    	}
    	if (nullptr == list1) {
    		p->next = list2;
    	}
    	if (nullptr == list2) {
    		p->next = list1;
    	}
    	p = temp->next;
    	delete temp;
    	return p;
    }
};