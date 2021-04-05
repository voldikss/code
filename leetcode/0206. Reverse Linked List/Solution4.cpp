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
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p = this->reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

int main() {
    Solution s;
    vector<int> nodes = {1, 2, 3, 4, 5};
    auto list = build_linkedlist(nodes);
    auto res = s.reverseList(list);
    cout << res << endl;
    return 0;
}
