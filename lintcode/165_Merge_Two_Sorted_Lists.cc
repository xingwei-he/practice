/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:165_Merge_Two_Sorted_Lists.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/ 3 11:05:00 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Merge two sorted (ascending) linked lists and return it as a new sorted list. The new sorted list should be made by splicing together the nodes of the two lists and sorted in ascending order.
 * 
 * Example
 * Given 1->3->8->11->15->null, 2->null , return 1->2->3->8->11->15->null.
 */

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
   * @param l1: ListNode l1 is the head of the linked list
   * @param l2: ListNode l2 is the head of the linked list
   * @return: ListNode head of linked list
   */
  ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    while (nullptr != p1 && nullptr != p2) {
      if(p1->val < p2->val) {
	tail->next = p1;
	p1 = p1->next;
      } else {
	tail->next = p2;
	p2 = p2->next;
      }
      tail = tail->next;
      tail->next = nullptr;
    }
    if (nullptr != p1 && nullptr == p2) {
      tail->next = p1;
    } else if (nullptr == p1 && nullptr != p2) {
      tail->next = p2;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    return head;
  }
};

int main() {
  return 0;
}

