/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:104_Merge_k_Sorted_Lists.cc
 * Author:
 * Mail:
 * Created Time:2017年12月17日 星期日 16时59分03秒
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 *
 * Example
 *
 * Given lists:
 * [
 *   2->4->null,
 *   null,
 *   -1->null
 * ],
 * return -1->2->4->null.
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * };
 */

class Solution {
public:
  /**
   * @param lists: a list of ListNode
   * @return: The head of one sorted list.
   */
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    head = new ListNode(-1);// 创建临时头节点方便操作
    tail = head;
    ListNode* min_ptr = nullptr;
    int min_pos = 0;
    bool is_empty = false;
    while (!is_empty) {
      min_ptr = nullptr;
      min_pos = 0;
      int i = 0;
      while (i < lists.size()) {
	if (nullptr == lists[i]) {
	  i++;
	  continue;
	}
	if (nullptr == min_ptr) {
	  min_ptr = lists[i];
	  min_pos = i;
	} else {
	  if (min_ptr->val > lists[i]->val) {
	    min_ptr = lists[i];
	    min_pos = i;
	  }
	}
	i++;
      }
      if (nullptr != min_ptr) {
	lists[min_pos] = min_ptr->next;
	min_ptr->next = nullptr;
	tail->next = min_ptr;
	tail = tail->next;
      } else {
	is_empty = true;
      }
    }
    ListNode* d = head;
    head = head->next;
    delete d;
    return head;
  }
};

int main() {
  vector<ListNode*> lists;
  ListNode* ln = new ListNode(1);
  lists.push_back(ln);
  Solution sl;
  ListNode* head = sl.mergeKLists(lists);
  for (ListNode* p = head; p != nullptr; p = p->next) {
    cout << p->val << "  ";
  }
  cout << endl;
  return 0;
}
