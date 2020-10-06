#include "../../include/linkedlist.cpp"
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
#include <variant>
#include <vector>
using namespace std;

class Solution {
  public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        deque<ListNode *> dq;
        ListNode *p = head;
        while (p) {
            dq.push_back(p);
            p = p->next;
        }

        p = dq.front();   // p = head;
        dq.pop_front();
        while (true) {
            if (dq.empty()) break;
            p->next = dq.back();
            dq.pop_back();
            p = p->next;

            if (dq.empty()) break;
            p->next = dq.front();
            dq.pop_front();
            p = p->next;
        }
        p->next = nullptr;
    }
};

int main() {

    return 0;
}
