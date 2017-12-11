#include "practice/include/base.h"

using namespace std;

/*
 * Sort a linked list in O(n log n) time using constant space complexity.

 * Example
 * Given 1->3->2->null, sort it to 1->2->3->null.
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
   * @param head: The head of linked list.
   * @return: You should return the head of the sorted linked list, using constant space complexity.
   */

  /*
   * 快速排序在整体无序的情况下时间复杂度达到 O(nlog(n))
   * 但是在完全有序（最坏情况）的时候时间复杂度达到O(n^2)
   * 因此不满足题目对时间复杂度的要求！
   */
  /* quickSort
  // 链表的快速排序
  void splitList(ListNode* left, ListNode* right, ListNode*& pl, ListNode*& p, ListNode*& pr) {
    ListNode* head = new ListNode(-1);
    head->next = left;
    ListNode* pivot = right;

    ListNode* pi = head;
    ListNode* pj = head->next;
    int temp = 0;
    while (pj != pivot) {
      // 该循环结束后，pj 指向 pivot
      if (pj->val <= pivot->val) {
	pi = pi->next;
	temp = pj->val;
	pj->val = pi->val;
	pi->val = temp;
      }
      pj = pj->next;
    }

    p = pi->next;
    pr = p->next;
    if (pi == head) {
      pl = nullptr;
    } else {
      pl = pi;
    }

    temp = pivot->val;
    pivot->val = p->val;
    p->val = temp;
    
    delete head;
    head = nullptr;
  }
  
  // left is the first node ptr of list
  // right is the laste node ptr of list
  void quickSortList(ListNode* left, ListNode* right) {
    if (left != right) {
      ListNode* pl = nullptr;
      ListNode* pr = nullptr;
      ListNode* p = nullptr;
      splitList(left, right, pl, p, pr);
      if (nullptr != pl) {
	quickSortList(left, pl);
      }
      if (nullptr != pr) {
	quickSortList(pr, right);
      }
    }
  }

  ListNode * sortList(ListNode * head) {
    if (nullptr == head) {
      return nullptr;
    }
    ListNode* left = head;
    ListNode* right = head;
    while (nullptr != right->next) {
      right = right->next;
    }
    quickSortList(left, right);
    return head;
  }
  quickSort */

  //  归并排序
  ListNode* getMidNode(ListNode* head) {
    // 利用快慢指针找到中间节点
    if (nullptr == head) {
      return head;
    }
    ListNode* p1 = head;// 慢指针
    ListNode* p2 = head;// 快指针
    while (nullptr != p2->next && nullptr != p2->next->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }
    return p1;
  }

  ListNode* mergeSortedList(ListNode* h1, ListNode* h2) {
    if (nullptr == h1) {
      return h2;
    } else if (nullptr == h2) {
      return h1;
    }
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
    while (nullptr != h1 && nullptr != h2) {
      if (h1->val <= h2->val) {
	p->next = h1;
	h1 = h1->next;
      } else {
	p->next = h2;
	h2 = h2->next;
      }
      p = p->next;
    }
    if (nullptr == h1) {
      p->next = h2;
    } else {
      p->next = h1;
    }
    p = head;
    head = head->next;
    delete p;
    p = nullptr;
    return head;
  }

  ListNode * sortList(ListNode * head) {
    if (nullptr == head || nullptr == head->next) {
      return head;
    }
    ListNode* mid = getMidNode(head);
    ListNode* sorted_right_head = sortList(mid->next);
    mid->next = nullptr;
    ListNode* sorted_left_head = sortList(head);
    return mergeSortedList(sorted_left_head, sorted_right_head);
  }
};

int main() {
  /* 归并测试 */
  ListNode* head = new ListNode(-1);
  ListNode* ptr = head;
  int arr[10] = {3,7,2,5,0,1,4,8,6,9};
  cout << "origin array:" << endl;
  for (int i = 0; i < 10; i++) {
    ListNode* temp = new ListNode(arr[i]);
    ptr->next = temp;
    ptr = ptr->next;
    cout << ptr->val << "  ";
  }
  cout << endl;
  ptr = head;
  head = head->next;
  delete ptr;
  ptr = nullptr;
  Solution sl;
  //ptr = sl.getMidNode(head);
  ptr = sl.sortList(head);
  while (nullptr != ptr) {
    cout << ptr->val << "  ";
    ptr = ptr->next;
  }
  cout << endl;

  /* 快排测试
  ListNode* head = new ListNode(-1);
  ListNode* ptr = head;
  int arr[10] = {3,7,2,5,0,1,4,8,6,9};
  for (int i = 0; i < 10; i++) {
    ListNode* temp = new ListNode(arr[i]);
    ptr->next = temp;
    ptr = ptr->next;
    cout << ptr->val << "  ";
  }
  cout << endl;
  ptr = head;
  head = head->next;
  delete ptr;
  ptr = nullptr;
  Solution sl;
  ListNode* left = head;
  ListNode* right = head;
  while (right->next != nullptr) {
    right = right->next;
  }
  ListNode* p1 = nullptr;
  ListNode* p2 = nullptr;
  ListNode* p = nullptr;
  sl.splitList(left, right, p1, p,p2);
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  if (nullptr == p1) {
    cout << "p1 is nullptr" << endl;
  } else {
    cout << "p1:" << p1->val << endl;
  }
  if (nullptr == p) {
    cout << "p is nullptr" << endl;
  } else {
    cout << "p:" << p->val << endl;
  }
  if (nullptr == p2) {
    cout << "p2 is nullptr" << endl;
  } else {
    cout << "p2:" << p2->val << endl;
  }

  cout << "**\t**\t**\t**" << endl;
  sl.quickSortList(left, right);
  ListNode* it = left;
  while (nullptr != it) {
    cout << it->val << "  ";
    it = it->next;
  }
  cout << endl;
  快排测试 */

  return 0;
}
