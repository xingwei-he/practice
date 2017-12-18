/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:167_Add_Two_Numbers.cc
 * Author:
 * Mail:
 * Created Time:星期一 12/18 17:08:24 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

 * Example
 * Given 7->1->6 + 5->9->2. That is, 617 + 295.
 * Return 2->1->9. That is 912.
 * Given 3->1->5 and 5->9->2, return 8->0->8.
 */

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
  /*
   * @param l1: the first list
   * @param l2: the second list
   * @return: the sum list of l1 and l2
   */
  ListNode * addLists(ListNode * l1, ListNode * l2) {
    if (nullptr == l1 && nullptr == l2) {
      return nullptr;
    }
    ListNode* head = new ListNode(-1);// head 指向临时头节点便于操作
    ListNode* tail = head;
    int carry = 0;
    while (nullptr != l1 || nullptr != l2 || carry != 0) {
      int d1 = 0;
      if (nullptr != l1) {
	d1 = l1->val;
	l1 = l1->next;
      }
      int d2 = 0;
      if (nullptr != l2) {
	d2 = l2->val;
	l2 = l2->next;
      }
      int d = (carry + d1 + d2) % 10;
      carry = (carry + d1 + d2) / 10;
      tail->next = new ListNode(d);
      tail = tail->next;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
};

int main() {
  ListNode* a1 = new ListNode(9);
  ListNode* a2 = new ListNode(9);
  a1->next = a2;
  ListNode* b1 = new ListNode(9);
  Solution sl;
  ListNode* res = sl.addLists(a1, b1);
  for (ListNode* p = res; nullptr != p; p = p->next) {
    cout << p->val << "  ";
  }
  cout << endl;
  return 0;
}
