#include "../../vital/linkedlist.cpp"
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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *new_head = new ListNode;
        new_head->next = head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur) {
            if (pre->val > cur->val) {
                ListNode *tmp = new_head;
                while (tmp->next->val < cur->val) tmp = tmp->next;
                pre->next = cur->next;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = pre->next;
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return new_head->next;
    }
};

int main() {
    ListNode *l = build_linkedlist({4, 2, 1, 3});
    Solution s;
    ListNode *res = s.insertionSortList(l);
    cout << res << endl;
    return 0;
}
