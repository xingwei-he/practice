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
 * 2 -> 3 - 6 - 7 - 9
 *          ->
 */

ListNode* LinkedList::getAnotherCommonLinkedList() {
  ListNode* head = new ListNode(2);
  head->next = new ListNode(3);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(7);
  head->next->next->next->next = new ListNode(9);
  return head;
}

/**
 * 1 - 2 - 3 - 7 - 8
 *     ->      |  
 *         5 - 6 
 *         ->   
 */
void LinkedList::getIntersectedLinkedLists(
    ListNode*& l1, ListNode*& l2) {
  l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(3);
  l1->next->next->next = new ListNode(7);
  l1->next->next->next->next = new ListNode(8);
  l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = l1->next->next->next;
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
