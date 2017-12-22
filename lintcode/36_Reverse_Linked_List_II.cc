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
    // 创建临时头节点便于操作
    ListNode* temp_head = new ListNode(-1);
    temp_head->next = head;
    // 用 left_tail 指向第 m-1 个节点
    ListNode* left_tail = temp_head;
    for (int i = 0; i < m - 1; i++) {
      left_tail = left_tail->next;
    }
    // 用 cur_head 指向第 m 个节点
    ListNode* cur_head = left_tail->next;
    // 用 right_head 指向第 n+1 个节点
    ListNode* right_head = cur_head;
    for (int i = 0; i < n - m + 1; i++) {
      right_head = right_head->next;
    }
    // 将 left_tail->next 指向 right_head
    left_tail->next = right_head;
    
    ListNode* p = nullptr;
    while (cur_head != right_head) {
      p = cur_head;
      cur_head = cur_head->next;
      p->next = left_tail->next;
      left_tail->next = p;
    }
    p = temp_head->next;
    delete temp_head;
    return p;
  }
};

int main() {
  ListNode* n1 = new ListNode(1);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(3);
  ListNode* n4 = new ListNode(4);
  ListNode* n5 = new ListNode(5);
  ListNode* n6 = new ListNode(6);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  Solution sl;
  ListNode* head = sl.reverseBetween(n1, 5, 6);
  for (ListNode* p = head; p != nullptr; p = p->next) {
    cout << p->val << "  ";
  }
  cout << endl;

  return 0;
}
