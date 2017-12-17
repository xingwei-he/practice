/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:103_Linked_List_Cycle_II.cc
 * Author:
 * Mail:
 * Created Time:2017年12月17日 星期日 11时47分55秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 *
 * Example
 * Given -21->10->4->5, tail connects to node index 1，return 10
 */

/**
 * Def                                                                                 inition of ListNode
 * c nlass ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * };
 */

class Solution {
public:
  /*
   * @param head: The first node of linked list.
   * @return: The node where the cycle begins. if there is no cycle, return null
   */

  // 快慢指针，相遇后再从头节点和相遇点开始搜索（每次一步），再次相遇时就是环的起始节点
  ListNode* hasCycle(ListNode * head) {
    if (nullptr == head) {
      return nullptr;
    }
    ListNode* res = nullptr;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (nullptr != p2->next && nullptr != p2->next->next) {
      p1 = p1->next;
      p2 = p2->next->next;
      if (p1 == p2) {
	res = p1;
	break;
      }
    }
    return res;
  }

  ListNode * detectCycle(ListNode * head) {
    if (nullptr == head) {
      return nullptr;
    }
    ListNode* s = nullptr;// 指向环的起始节点
    ListNode* p = nullptr;// 指向快慢指针的相遇点
    p = hasCycle(head);
    if (nullptr != p) {
      s = head;
      while (s != p) {
	s = s->next;
	p = p->next;
      }
    }
    return s;
  }
};

int main() {
  return 0;
}
