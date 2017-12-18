/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:221_Add_Two_Numbers_II.cc
 * Author:
 * Mail:
 * Created Time:星期一 12/18 18:04:08 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in forward order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
 *
 * Example
 * Given 6->1->7 + 2->9->5. That is, 617 + 295.
 * Return 9->1->2. That is, 912.
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
   * @param l1: The first list.
   * @param l2: The second list.
   * @return: the sum list of l1 and l2.
   */
  ListNode * addLists2(ListNode * l1, ListNode * l2) {
    if (nullptr == l1 && nullptr == l2) {
      return nullptr;
    }
    ListNode* head = new ListNode(-1);// 创建临时头节点方便操作
    stack<int> st1;
    stack<int> st2;
    for (ListNode* p1 = l1; p1 != nullptr; p1 = p1->next){
      st1.push(p1->val);
    }
    for (ListNode* p2 = l2; p2 != nullptr; p2 = p2->next) {
      st2.push(p2->val);
    }
    int carry = 0;
    while (!st1.empty() || !st2.empty() || 0 != carry) {
      int d1 = 0;
      if (!st1.empty()) {
	d1 = st1.top();
	st1.pop();
      }
      int d2 = 0;
      if (!st2.empty()) {
	d2 = st2.top();
	st2.pop();
      }
      int d = (carry + d1 + d2) % 10;
      carry = (carry + d1 + d2) / 10;
      ListNode* t = new ListNode(d);
      t->next = head->next;
      head->next = t; 
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
};

int main() {
  return 0;
}
