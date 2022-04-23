/**************************************
* He Xingwei, All Rights Reserved.
* Filename:23.cpp
* Date:2022-04-23 19:00:11
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); // 链表个数
        auto select_list = [](vector<ListNode*> &lists) -> int {
                int cur = -1;
                for (int i = 0; i < lists.size(); i++) {
                    if (lists[i] != nullptr) {
                        cur = i;
                        break;
                    }
                }
                for (int i = cur; i < lists.size(); i++) {
                    if (lists[i] == nullptr) {
                        continue;
                    }
                    if (lists[i]->val < lists[cur]->val) {
                        cur = i;
                    }
                }
                return cur;
            };
        ListNode *head = new ListNode();
        ListNode *p = head;
        int cur = select_list(lists);
        while (cur != -1) {
            p->next = lists[cur];
            lists[cur] = lists[cur]->next;
            p = p->next;
            p->next = nullptr;
            cur = select_list(lists);
        }
        p = head->next;
        delete head;
        return p;
    }
};