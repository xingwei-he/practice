/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:main.cc
 * Author:
 * Mail:
 * Created Time:2018年01月30日 星期二 22时54分02秒
 ***************************************************/
#include <iostream>

#include "linked_list.h"
#include "linked_list_processor.h"

using namespace std;

int main() {
  LinkedList linked_list;
  ListNode* common_linked_list_head = linked_list.getCommonLinkedList();
  //ListNode* ring_linked_list_head = linked_list.getRingLinkedList();

  LinkedListProcessor linked_list_processor;

  // 1. 求单链表中节点个数
  int node_num = linked_list_processor.getListLength(common_linked_list_head);
  cout << node_num << endl;

  // 2. 反转单链表

  return 0;
}
