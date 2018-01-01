/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:112_Remove_Duplicates_from_Sorted_List.cc
 * Author:
 * Mail:
 * Created Time:2018年01月01日 星期一 18时24分39秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * Example
 *
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
   * @param head: head is the head of the linked list
   * @return: head of linked list
   */
  ListNode * deleteDuplicates(ListNode * head) {
    if (nullptr == head) {
      return nullptr;
    }
    ListNode* pre = head;
    ListNode* cur = head->next;
    while (nullptr != cur) {
      if (pre->val == cur->val) {
	pre->next = cur->next;
	delete cur;
	cur = pre->next;
      } else {
	pre = cur;
	cur = cur->next;
      }
    }
    return head;
  }
};

int main() {
  return 0;
}
