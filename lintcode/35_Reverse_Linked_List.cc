/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:35_Reverse_Linked_List.cc
 * Author:
 * Mail:
 * Created Time:2017年12月21日 星期四 22时34分59秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Reverse a linked list.
 *
 * Example
 * For linked list 1->2->3, the reversed linked list is 3->2->1
 */

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
  /*
   * @param head: n
   * @return: The new head of reversed linked list.
   */
  ListNode * reverse(ListNode * head) {
    if (nullptr == head) {
      return nullptr;
    }
    ListNode* thead = new ListNode(-1);
    ListNode* p = head;
    ListNode* pnext = nullptr;
    while (nullptr != p) {
      pnext = p->next;
      p->next = thead->next;
      thead->next = p;
      p = pnext;
    }
    p = thead->next;
    delete thead;
    return p;
  }
};

int main() {
  return 0;
}


