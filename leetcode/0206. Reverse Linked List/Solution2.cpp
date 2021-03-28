#include "../../include/linkedlist.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode *save_head = head;
        ListNode *p = head;
        ListNode *q = p->next;
        ListNode *r = q->next;
        while (q) {
            q->next = p;
            if (!r) break;
            p = q;
            q = r;
            r = r->next;
        }
        save_head->next = nullptr;
        return q;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    vector<int> nodes = {1, 2, 3, 4, 5};
    for (auto x : nodes) {
        ListNode *node = new ListNode(x);
        p->next = node;
        p = p->next;
    }
    p->next = nullptr;

    auto res = s.reverseList(head->next);
    cout << res << endl;
    return 0;
}
