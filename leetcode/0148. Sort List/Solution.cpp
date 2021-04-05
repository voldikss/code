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
#include <variant>
#include <vector>
using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *tail = slow->next;
        slow->next = nullptr;
        return this->mergeSort(head, tail);
    }

    ListNode *mergeSort(ListNode *l1, ListNode *l2) {
        l1 = this->sortList(l1);
        l2 = this->sortList(l2);
        return this->mergeList(l1, l2);
    }

    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val > l2->val) return this->mergeList(l2, l1);
        // termination condition
        l1->next = this->mergeList(l1->next, l2);
        return l1;
    }
};

int main() {
    Solution s;
    auto l = build_linkedlist<int>({-1, 5, 3, 4, 0});
    auto res = s.sortList(l);
    cout << res << endl;
    return 0;
}
