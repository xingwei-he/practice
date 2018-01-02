/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:174_Remove_Nth_Node_From_End_of_List.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 2 13:53:20 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * Notice
 *   The minimum number of nodes in list is n.
 *
 * Example
 * Given linked list: 1->2->3->4->5->null, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5->null.
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
   * @param head: The first node of linked list.
   * @param n: An integer
   * @return: The head of linked list.
   */
  ListNode * removeNthFromEnd(ListNode * head, int n) {
    if (nullptr == head) {
      return head;
    }
    // 临时头节点
    ListNode* thead = new ListNode(-1);
    thead->next = head;

    ListNode* p = head;
    ListNode* pn = thead;
    for (int i = 0; i < n; i++) {
      p = p->next;
    }
    while (nullptr != p) {
      p = p->next;
      pn = pn->next;
    }
    ListNode* temp = pn->next;
    pn->next = pn->next->next;
    delete temp;
    head = thead->next;
    delete thead;
    return head;
  }
};

int main() {
  return 0;
}

