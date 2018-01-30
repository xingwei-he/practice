/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:linked_list.cc
 * Author:
 * Mail:
 * Created Time:2018年01月26日 星期五 00时18分10秒
 ***************************************************/
#include <iostream>

#include "linked_list.h"

using namespace std;

LinkedList::LinkedList() {}
LinkedList::~LinkedList() {}

/**
 * 1 - 2 - 3 - 4 - 5 - 6
 *         ->
 */

ListNode* LinkedList::getCommonLinkedList() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  return head;
}

/**              
 *                <-
 *             9 - 8 - 7 
 *             |       |
 * 1 - 2 - 3 - 4 - 5 - 6
 *     ->          ->
 */
ListNode* LinkedList::getRingLinkedList() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);
  head->next->next->next->next->next->next->next->next = new ListNode(9);
  head->next->next->next->next->next->next->next->next->next = head->next->next->next;
  return head;
}
