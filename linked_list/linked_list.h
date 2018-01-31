/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:linked_list.h
 * Author:
 * Mail:
 * Created Time:2018年01月26日 星期五 00时15分11秒
 ***************************************************/
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "practice/include/base.h"

class LinkedList {
public:
  LinkedList();
  ~LinkedList();

  ListNode* getCommonLinkedList();
  ListNode* getAnotherCommonLinkedList();
  void getIntersectedLinkedLists(ListNode*& l1, ListNode*& l2);
  ListNode* getRingLinkedList();
};

#endif

