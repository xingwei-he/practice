/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:451_Swap_Nodes_in_Pairs.cc
 * Author:
 * Mail:
 * Created Time:星期五  1/ 5 10:35:05 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * Example
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
   * @param head: a ListNode
   * @return: a ListNode
   */
  ListNode * swapPairs(ListNode * head) {
    if (nullptr == head) {
      return nullptr;
    }
    ListNode* p1 = head;
    while (nullptr != p1) {
      ListNode* p2 = p1->next;
      if (nullptr == p2) {
	break;
      }
      int temp = p1->val;
      p1->val = p2->val;
      p2->val = temp;
      p1 = p1->next->next;
    }
    return head;
  }
};

int main() {
  return 0;
}

