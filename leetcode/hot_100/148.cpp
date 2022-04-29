#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 递归结束条件
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        // 断链
        ListNode *mid = get_middle_node(head);
        ListNode *right_head = mid->next;
        mid->next = nullptr;
        // 递归向下
        ListNode *left_sorted_head = sortList(head);
        ListNode *right_sorted_head = sortList(right_head);
        // 把有序链表合并
        return merge_lists(left_sorted_head, right_sorted_head);
    }
private:
    // 获取链表的中间节点指针
    ListNode * get_middle_node(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        ListNode *p1 = head, *p2 = head; // 快慢指针
        while (nullptr != p2->next && nullptr != p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    // 合并两个有序链表并返回新链表头结点指针
    ListNode * merge_lists(ListNode *head1, ListNode *head2) {
        ListNode *temp = new ListNode(-1);
        ListNode *cur = temp;
        while (nullptr != head1 && nullptr != head2) {
            if (head1->val <= head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
            //cur->next = nullptr; // 断链，好习惯
        }
        if (nullptr != head1) {
            cur->next = head1;
            head1 = head1->next;
        }
        if (nullptr != head2) {
            cur->next = head2;
            head2 = head2->next;
        }
        cur = temp->next;
        delete temp;
        return cur;
    }
};