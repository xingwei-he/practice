/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:linked_list_processor.cc
 * Author:
 * Mail:
 * Created Time:2018年01月25日 星期四 22时59分02秒
 ***************************************************/
#include <iostream>

#include "linked_list_processor.h"

using namespace std;

LinkedListProcessor::LinkedListProcessor() {}
LinkedListProcessor::~LinkedListProcessor() {}

// 1. 求单链表中节点个数

unsigned int LinkedListProcessor::getListLength(ListNode* head) {
  if (nullptr == head) {
    return 0;
  }
  unsigned int len = 0;
  ListNode* p = head;
  while (nullptr != p) {
    len++;
    p = p->next;
  }
  return len;
}

// 2. 反转单链表

ListNode* LinkedListProcessor::reverseList(ListNode* head) {
  if (nullptr == head || nullptr == head->next) {
    return head;
  }
  ListNode* pre_ptr = nullptr;
  ListNode* cur_ptr = head;
  ListNode* next_ptr = nullptr;
  while (nullptr != cur_ptr) {
    next_ptr = cur_ptr->next;
    cur_ptr->next = pre_ptr;
    pre_ptr = cur_ptr;
    cur_ptr = next_ptr;
  }
  return pre_ptr;
}

// 3. 查找单链表中的倒数第 K 个节点（K > 0）

ListNode* LinkedListProcessor::getKthNode(ListNode* head, unsigned int k) {
  if (0 == k || nullptr != head) {
    return nullptr;
  }
  ListNode* p1 = head;
  ListNode* p2 = head;
  for (int i = 0; i < k; i++) {
    p2 = p2->next;
  }
  while (nullptr != p2) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1;
}

// 4. 查找单链表的中间节点
ListNode* LinkedListProcessor::getMiddleNode(ListNode* head) {
  if (nullptr == head || nullptr == head->next) {
    return nullptr;
  }

  ListNode* p1 = head;
  ListNode* p2 = head;
  while (nullptr != p2->next || nullptr != p2->next->next) {
    p1 = p1->next;
    p2 = p2->next->next;
  }
  return p1;
}

// 5. 从尾到头打印单链表
void LinkedListProcessor::reversePrintList(ListNode* head) {
  if (nullptr == head) {
    return;
  }
  stack<ListNode*> st;
  ListNode* p = head;
  while (nullptr != p) {
    st.push(p);
  }
  while (!st.empty()) {
    p = st.top();
    st.pop();
    cout << setw(4) << p->val;
  }
}

// 6. 合并两个有序链表成一个有序链表
ListNode* mergeSortedList(ListNode* l1, ListNode* l2) {
  if (nullptr == l1) {
    return l2;
  }
  if (nullptr == l2) {
    return l1;
  }
  ListNode* p1 = l1;
  ListNode* p2 = l2;
  ListNode* p = nullptr;
  ListNode* phead = nullptr;
  if (p1->val < p2->val) {
    p = p1;
    p->next = nullptr;
    p1 = p1->next;
  } else {
    p = p2;
    p->next = nullptr;
    p2 = p2->next;
  }
  phead = p;
  while (nullptr != p1 && nullptr != p2) {
    if (p1->val < p2->val) {
      p->next = p1;
      p1 = p1->next;
      p = p->next;
      p->next = nullptr;
    } else {
      p->next = p2;
      p2 = p2->next;
      p = p->next;
      p->next = nullptr;
    }
  }
  if (nullptr == p1) {
    p->next = p2;
  }
  if (nullptr == p2) {
    p->next = p1;
  }
  return phead;
}
