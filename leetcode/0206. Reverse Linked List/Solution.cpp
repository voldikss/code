#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* p = head;
        ListNode* tail = head;
        while (tail->next) tail = tail->next;

        this->rev(head);

        p->next = nullptr;
        return tail;
    }

    ListNode* rev(ListNode* node) {
        if (!node->next) return node;
        ListNode* p = this->rev(node->next);
        p->next = node;
        return node;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
    vector<int> nodes = {1, 2, 3, 4, 5};
    for (auto x : nodes) {
        ListNode* node = new ListNode(x);
        p->next = node;
        p = p->next;
    }
    p->next = nullptr;

    auto res = s.reverseList(head->next);
    cout << res << endl;
    return 0;
}
