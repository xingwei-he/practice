/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:linked_list_processor.h
 * Author:
 * Mail:
 * Created Time:2018年01月25日 星期四 22时35分34秒
 ***************************************************/
#ifndef _LINKED_LIST_PROCESSOR_H
#define _LINKED_LIST_PROCESSOR_H

#include "practice/include/base.h"

class LinkedListProcessor {
public:
  LinkedListProcessor();
  virtual ~LinkedListProcessor();
  
  // 1. 求单链表中节点个数
  unsigned int getListLength(ListNode* head);

  // 2. 反转单链表
  ListNode* reverseList(ListNode* head);

  // 3. 查找单链表中的倒数第 K 个节点（K > 0）
  ListNode* getKthNode(ListNode* head, unsigned int k);

  // 4. 查找单链表的中间节点
  ListNode* getMiddleNode(ListNode* head);

  // 5. 从尾到头打印单链表
  void reversePrintList(ListNode* head);

  // 6. 合并两个有序链表成一个有序链表
  ListNode* mergeSortedList(ListNode* l1, ListNode* l2);
};

#endif

