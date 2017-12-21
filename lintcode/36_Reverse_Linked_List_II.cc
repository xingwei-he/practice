/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:36_Reverse_Linked_List_II.cc
 * Author:
 * Mail:
 * Created Time:2017年12月21日 星期四 23时11分33秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Reverse a linked list from position m to n.
 *
 * Notice
 * Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example
 *
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.
 */

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
  /*
   * @param head: ListNode head is the head of the linked list 
   * @param m: An integer
   * @param n: An integer
   * @return: The head of the reversed ListNode
   */
  ListNode * reverseBetween(ListNode * head, int m, int n) {
    if (nullptr == head) {
      return nullptr;
    }
    if (m == n) {
      return head;
    }
    ListNode* left_head = new ListNode(-1);
    ListNode* phead = left_head;
    ListNode* ptail = phead;
    for (int i = 0; i < m; i++) {
      phead = phead->next;
    }
    for (int i = m; i < n; i++) {
      ptail = ptail->next;
    }
    ListNode* left_tail = left_head;
    while (left_tail->next != phead) {
      left_tail = left_tail->next;
    }
    ListNode* p = nullptr;
    ListNode* right_head = ptail->next;
    while (p != right_head) {
      p = phead;
      phead = phead->next;
      p->next = left_tail->next;
      left_tail->next = p;
    }
    while (nullptr != left_tail->next) {
      left_tail = left_tail->next;
    }
    left_tail->next = right_head;
    ListNode* temp = left_head->next;
    delete left_head;
    return temp;
  }
};

int main() {
  return 0;
}
