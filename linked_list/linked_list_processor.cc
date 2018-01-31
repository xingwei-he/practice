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

ListNode* LinkedListProcessor::getKthNodeFromTail(ListNode* head, unsigned int k) {
  if (0 == k || nullptr == head) {
    return nullptr;
  }
  ListNode* p1 = head;
  ListNode* p2 = head;
  int len = 0;
  for (int i = 0; i < k && nullptr != p2; i++) {
    len++;
    p2 = p2->next;
  }
  if (len < k) {
    return nullptr;
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
  while (nullptr != p2->next && nullptr != p2->next->next) {
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
    p = p->next;
  }
  while (!st.empty()) {
    p = st.top();
    st.pop();
    cout << setw(4) << p->val;
  }
  cout << endl;
}

// 6. 合并两个有序链表成一个有序链表
ListNode* LinkedListProcessor::mergeSortedList(ListNode* l1, ListNode* l2) {
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
    p1 = p1->next;
    p->next = nullptr;
  } else {
    p = p2;
    p2 = p2->next;
    p->next = nullptr;
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


// 7. 判断链表中是否有环
bool LinkedListProcessor::hasCircle(ListNode* head) {
  if (nullptr == head) {
    return false;
  }
  ListNode* p1 = head;
  ListNode* p2 = head;
  bool has_circle = false;
  while (nullptr != p2->next && nullptr != p2->next->next) {
    p1 = p1->next;
    p2 = p2->next->next;
    if (p1 == p2) {
      has_circle = true;
      break;
    }
  }
  return has_circle;
}

// 8. 判断两个链表是否相交
bool LinkedListProcessor::isIntersected(ListNode* l1, ListNode* l2) {
  if (nullptr == l1 || nullptr == l2) {
    return false;
  }
  int len1 = getListLength(l1);
  int len2 = getListLength(l2);
  ListNode* p1 = l1;
  ListNode* p2 = l2;
  if (len1 > len2) {
    for (int i = 0; i < (len1 - len2); i++) {
      p1 = p1->next;
    }
  } else {
    for (int i = 0; i < (len2 - len1); i++) {
      p2 = p2->next;
    }
  }
  bool is_intersected = false;
  while (nullptr != p1 && nullptr != p2) {
    if (p1 == p2) {
      is_intersected = true;
      break;
    }
    p1 = p1->next;
    p2 = p2->next;
  }
  return is_intersected;
}

// 9. 求两个单链表相交的第一个节点
ListNode* LinkedListProcessor::getFirstCommonNode(ListNode* l1, ListNode* l2) {
  if (nullptr == l1 || nullptr == l2) {
    return nullptr;
  }
  int len1 = getListLength(l1);
  int len2 = getListLength(l2);
  ListNode* p1 = l1;
  ListNode* p2 = l2;
  if (len1 > len2) {
    for (int i = 0; i < (len1 - len2); i++) {
      p1 = p1->next;
    }
  } else {
    for (int i = 0; i < (len2 - len1); i++) {
      p2 = p2->next;
    }
  }
  ListNode* res = nullptr;
  while (nullptr != p1 && nullptr != p2) {
    if (p1 == p2) {
      res = p1;
      break;
    }
    p1 = p1->next;
    p2 = p2->next;
  }
  return res;
}
