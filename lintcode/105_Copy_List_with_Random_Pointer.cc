/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:105_Copy_List_with_Random_Pointer.cc
 * Author:
 * Mail:
 * Created Time:2017年12月17日 星期日 18时01分40秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
  /**
   * @param head: The head of linked list with a random pointer.
   * @return: A new head of a deep copy of the list.
   */
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode* rhead = nullptr;
    RandomListNode* rtail = nullptr;
    rhead = new RandomListNode(0);// 创建临时头节点，便于操作
    rtail = rhead;
    for (RandomListNode* tp = head; tp != nullptr; tp = tp->next) {
      rtail->next = new RandomListNode(tp->label);
      rtail = rtail->next;
    }
    // 删除临时头节点
    RandomListNode* temp = rhead;
    rhead = rhead->next;
    delete temp;
    temp = nullptr;

    // copy random
    RandomListNode* rp = rhead;// 指向待赋值 random 的节点
    RandomListNode* p = head;// 指向被复制 random 的节点
    while (nullptr != rp) {
      RandomListNode* rrand = rhead;
      RandomListNode* rand = head;
      while (rand != p->random) {
	//cout << "* " << rrand->label << "\t" << &rrand << endl;
	//cout << "* " << rand->label << "\t" << &rand << endl;
	rrand = rrand->next;
	rand = rand->next;
      }
      rp->random = rrand;
      rp = rp->next;
      p = p->next;
    }
    return rhead;
  }
};

int main() {
  RandomListNode* head = new RandomListNode(-1);
  Solution sl;
  RandomListNode* res = sl.copyRandomList(head);
  for (RandomListNode* p = res; p != nullptr; p = p->next) {
    cout << "label:" << p->label << endl;
  }
  return 0;
}

