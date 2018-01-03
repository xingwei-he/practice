/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:166_Nth_to_Last_Node_in_List.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/ 3 12:44:37 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Find the nth to last element of a singly linked list. 
 * The minimum number of nodes in list is n.
 *
 * Example
 * Given a List  3->2->1->5->null and n = 2, return node  whose value is 1.
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
   * @return: Nth to last node of a singly linked list. 
   */
  ListNode * nthToLast(ListNode * head, int n) {
    if (nullptr == head) {
      return nullptr;
    }
    ListNode* p1 = head;
    ListNode* p2 = head;
    for (int i = 0; i < n - 1; i++) {
      p2 = p2->next;
    }
    while (nullptr != p2->next) {
      p1 = p1->next;
      p2 = p2->next;
    }
    return p1;
  }
};

int main() {
  return 0;
}
