/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:102_Linked_List_Cycle.cc
 * Author:
 * Mail:
 * Created Time:2017年12月17日 星期日 11时29分11秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a linked list, determine if it has a cycle in it.
 *
 * Example
 * Given -21->10->4->5, tail connects to node index 1, return true
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *         ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * };
 */

class Solution {
public:
  /*
   * @param head: The first node of linked list.
   * @return: True if it has a cycle, or false
   */

  // 判断链表中是否有环一般就用快慢指针
  bool hasCycle(ListNode * head) {
    if (nullptr == head) {
      return false;
    }
    bool has_cycle = false;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (nullptr != p2->next && nullptr != p2->next->next) {
      p1 = p1->next;
      p2 = p2->next->next;
      if (p1 == p2) {
	has_cycle = true;
	break;
      }
    }
    return has_cycle;
  }
};

int main() {
  return 0;
}

