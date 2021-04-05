#include "../../include/global.hpp"
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head) return head;
        int cnt = 1;
        ListNode *start = head;
        ListNode *pre = nullptr;
        while (start && cnt < m) {
            pre = start;
            start = start->next;
            cnt++;
        }

        ListNode *p = start;
        ListNode *q = p->next;
        ListNode *tmp;
        while (q && cnt < n) {
            tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
            cnt++;
        }
        start->next = tmp;
        if (pre)
            pre->next = p;
        else
            head = p;

        return head;
    }
};

int main() {
    Solution s;
    vector<int> nodes = {1, 2, 3, 4, 5};
    auto list = build_linkedlist<int>(nodes);
    // auto res = s.reverseBetween(list, 2, 4);
    auto res = s.reverseBetween(list, 1, 4);
    cout << res << endl;
    return 0;
}
