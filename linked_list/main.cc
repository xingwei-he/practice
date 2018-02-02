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

void printList(ListNode* head) {
  for (ListNode* p = head; p != nullptr; p = p->next) {
    cout << p->val << " -> ";
  }
  cout << "nullptr" << endl;
}

int main() {
  LinkedList linked_list;
  ListNode* common_linked_list_head = linked_list.getCommonLinkedList();
  ListNode* ring_linked_list_head = linked_list.getRingLinkedList();

  LinkedListProcessor linked_list_processor;

  // 1. 求单链表中节点个数
  cout << "1. 求单链表中节点个数" << endl;
  printList(common_linked_list_head);
  int len = linked_list_processor.getListLength(common_linked_list_head);
  cout << "len:" << len << endl;

  // 2. 反转单链表
  cout << "2. 反转单链表" << endl;
  cout << "原链表\t";
  printList(common_linked_list_head);
  ListNode* reversed_head = linked_list_processor.reverseList(common_linked_list_head);
  cout << "翻转后链表\t";
  printList(reversed_head);
  // 再次翻转，还原链表
  cout << "还原链表\t";
  common_linked_list_head = linked_list_processor.reverseList(reversed_head);
  printList(common_linked_list_head);

  // 3. 查找单链表中的倒数第 K 个节点（K > 0）
  cout << "3. 查找单链表中的倒数第 K 个节点（K > 0）" << endl;
  printList(common_linked_list_head);
  int k = 5;
  cout << "k:" << k << endl;
  ListNode* p = linked_list_processor.getKthNodeFromTail(common_linked_list_head, k);
  if (nullptr != p) {
    cout << "the kth from tail:" << p->val << endl;
  } else {
    cout << "the kth from tail: nullptr" << endl;
  }
  k = 8;
  cout << "k:" << k << endl;
  p = linked_list_processor.getKthNodeFromTail(common_linked_list_head, k);
  if (nullptr != p) {
    cout << "the kth from tail:" << p->val << endl;
  } else {
    cout << "the kth from tail: nullptr" << endl;
  }

  // 4. 查找单链表的中间节点
  cout << "4. 查找单链表的中间节点" << endl;
  printList(common_linked_list_head);
  ListNode* p_mid = linked_list_processor.getMiddleNode(common_linked_list_head);
  cout << "the middle node:" << p_mid->val << endl;

  // 5. 从尾到头打印单链表
  cout << "5. 从尾到头打印单链表" << endl;
  printList(common_linked_list_head);
  linked_list_processor.reversePrintList(common_linked_list_head);

  // 6. 合并两个有序链表成一个有序链表
  cout << "6. 合并两个有序链表成一个有序链表" << endl;
  ListNode* temp_list_1 = linked_list.getCommonLinkedList();
  ListNode* temp_list_2 = linked_list.getAnotherCommonLinkedList();
  printList(temp_list_1);
  printList(temp_list_2);
  ListNode* merged_list = linked_list_processor.mergeSortedList(temp_list_1, temp_list_2);
  printList(merged_list);

  // 7. 判断链表中是否有环
  cout << "7. 判断链表中是否有环" << endl;
  bool has_circle = linked_list_processor.hasCircle(ring_linked_list_head);
  cout << "ring_linked_list_head:" << boolalpha << has_circle << endl;

  // 8. 判断两个链表是否相交
  cout << "8. 判断两个链表是否相交" << endl;
  ListNode* l1 = nullptr;
  ListNode* l2 = nullptr;
  linked_list.getIntersectedLinkedLists(l1, l2);
  bool is_intersected = linked_list_processor.isIntersected(l1, l2);
  cout << "is_intersected:" << boolalpha << is_intersected << endl;

  // 9. 求两个单链表相交的第一个节点
  cout << "9. 求两个单链表相交的第一个节点" << endl;
  ListNode* first_common_node = linked_list_processor.getFirstCommonNode(l1, l2);// l1 和 l2 经过上一步操作已经相交
  cout << "first common node:" << first_common_node->val << endl;

  // 10. 已知一个单链表中存在环，求进入环中的第一个节点

  // 11. 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted
  cout << "11. 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted" << endl;
  ListNode* temp_list = linked_list.getCommonLinkedList();
  cout << "原链表\t";
  printList(temp_list);
  linked_list_processor.deleteNode(temp_list_1, temp_list->next->next->next);
  cout << "删除节点后\t";
  printList(temp_list);

  return 0;
}
