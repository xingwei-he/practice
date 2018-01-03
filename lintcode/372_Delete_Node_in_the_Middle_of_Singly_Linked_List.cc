/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:372_Delete_Node_in_the_Middle_of_Singly_Linked_List.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/ 3 12:58:47 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
 *
 * Example
 * Linked list is 1->2->3->4, and given node 3, delete the node in place 1->2->4
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
   * @param node: the node in the list should be deletedt
   * @return: nothing
   */
  void deleteNode(ListNode * node) {
    if (nullptr == node) {
      return;
    }
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

int main() {
  return 0;
}
