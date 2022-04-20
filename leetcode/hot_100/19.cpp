/**************************************
* He Xingwei, All Rights Reserved.
* Filename:19.cpp
* Date:2022-04-20 17:31:12
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (nullptr == head) {
			return nullptr;
		}
		ListNode *p = new ListNode(); // 前置节点，方便操作，注意最后delete
		p->next = head;
		ListNode *pre = p;
		ListNode *p1 = head, *p2 = head;
		int step = 0;
		while (step < n && p2 != nullptr) {
			step++;
			p2 = p2->next;
		}
		if (step < n) { // 节点数小于n，无结果
			return head;
		}
		while (p2 != nullptr) {
			pre = pre->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		pre->next = p1->next;
		delete p1;
		head = p->next;
		delete p;
	}        
};
