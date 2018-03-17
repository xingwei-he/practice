#include "practice/include/base.h"

using namespace std;

/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.

 * Example
 * Given 1->4->3->2->5->2->null and x = 3,
 * return 1->2->2->4->3->5->null.
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
 * }
 */

class Solution {
public:
  /*
   * @param head: The first node of linked list
   * @param x: An integer
   * @return: A ListNode
   */

  ListNode* splitList(ListNode* head, int pivot) {
    if (nullptr == head) {
      return nullptr;
    }
    ListNode* temp = new ListNode(-1);
    temp->next = head;
    ListNode* left = temp;// left 指向左侧最后一个小于 pivot 的元素
    ListNode* right = temp;// right 指向 left 右侧最后一个大于等于 pivot 的元素
    while (nullptr != right->next) {
      while (nullptr != left->next && left->next->val < pivot) {
	left = left->next;
      }
      right = left;
      while (nullptr != right->next && right->next->val >= pivot) {
	right = right->next;
      }
      //cout << "left:" << left->val << " right:" << right->val << endl;
      if (left == right || nullptr == left->next || nullptr == right->next) {
	break;
      }
      // 将 right 后面的节点插入到 left 后面
      ListNode* t = right->next;
      right->next = t->next;
      t->next = left->next;
      left->next = t;
    }
    ListNode* h = temp->next;
    delete temp;
    temp = nullptr;
    return h;
  }

  ListNode * partition(ListNode * head, int x) {
    return splitList(head, x);
  }
};

int main() {
  ListNode* head = new ListNode(1);
  ListNode* res = nullptr;
  Solution sl;
  res = sl.partition(head, 0);
  ListNode* ptr = res;
  while (ptr != nullptr) {
    cout << ptr->val << "  ";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}
