#include "practice/include/base.h"

using namespace std;

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
  /*
   * @param head: The head of linked list.
   * @return: nothing
   */
  void reorderList(ListNode * head) {
    if (nullptr == head || nullptr == head->next) {
      return;
    }
    // 利用快慢指针分割链表
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (true) {// 循环结束后链表被分为前后两段
      if (nullptr == p2->next || nullptr == p2->next->next) {
	ListNode* t = p1;
	p1 = p1->next;
	t->next = nullptr;
	break;
      } else {
	p1 = p1->next;
	p2 = p2->next->next;
      }
    }

    ListNode* h1 = head;// 前半段头指针
    ListNode* h2 = p1;// 后半段头指针
    // 翻转后半段链表
    p2 = p1->next;
    p1->next = nullptr;
    while (nullptr != p2) {
      ListNode* temp = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 =temp;
    }
    h2 = p1;// 翻转后的后半段头指针

    /* debug
    ListNode* d = h1;
    while (nullptr != d) {
      cout << d->val << " ";
      d = d->next;
    }
    cout << endl;
    d = h2;
    while (nullptr != d) {
      cout << d->val << " ";
      d = d->next;
    }
    cout << endl;
    */

    // 合并
    while (nullptr != h2) {
      ListNode* temp = h2;
      h2 = h2->next;
      temp->next = h1->next;
      h1->next = temp;
      h1 = temp->next;
    }
  }
};

int main() {
  ListNode* head = new ListNode(-1);
  ListNode* ptr = head;
  for (int i = 1; i <= 10; i++) {
    ListNode* temp = new ListNode(i);
    ptr->next = temp;
    ptr = ptr->next;
  }
  ptr = head;
  head = head->next;
  delete ptr;
  ptr = nullptr;
  Solution sl;
  sl.reorderList(head);
  ptr = head;
  while (nullptr != ptr) {
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}
