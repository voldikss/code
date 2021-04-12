#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main() {
    vector<int> nodes = {1, 2, 3, 4, 5};
    auto list = build_linkedlist<int>(nodes);
    Solution s;
    auto res = s.reverseList(list);
    cout << res << endl;
    return 0;
}
