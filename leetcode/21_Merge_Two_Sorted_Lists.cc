#include "practice/include/base.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (nullptr == l1 && nullptr == l2) {
      return nullptr;
    } else if (nullptr == l1) {
      return l2;
    } else if (nullptr == l2) {
      return l1;
    }
    // la 指向头节点小的
    ListNode* la = nullptr;
    ListNode* lb = nullptr;
    if (l2->val >= l1->val) {
      la = l1;
      lb = l2;
    } else {
      la = l2;
      lb = l1;
    }

    ListNode* pa = la;
    ListNode* pb = lb;
    // 初始化头节点
    ListNode* p = pa;
    pa = pa->next;
    p->next = nullptr;

    ListNode* temp = p;
    while (nullptr != pa && nullptr != pb) {
      if (pa->val < pb->val) {
	temp->next = pa;
	pa = pa->next;
	temp = temp->next;
	temp->next = nullptr;
      } else {
	temp->next = pb;
	pb = pb->next;
	temp = temp->next;
	temp->next = nullptr;
      }
    }
    if (nullptr != pa) {
      temp->next = pa;
    } else {
      temp->next = pb;
    }
    return p;
  }
};

int main() {
  return 0;
}
