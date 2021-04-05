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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *new_head = new ListNode;
        new_head->next = head;
        ListNode *p = new_head;
        while (p->next) {
            ListNode *Next = p->next;
            if (p->val > p->next->val) {
                ListNode *pp = new_head;
                while (pp != p) {
                    if (pp->next->val > p->next->val) {
                        Next = p->next;
                        ListNode *tmp = pp->next;
                        pp->next = p->next;
                        p->next = p->next->next;
                        pp->next->next = tmp;
                        break;
                    }
                    pp = pp->next;
                }
            }
            p = Next;
        }
        return new_head->next;
    }
};

int main() {
    ListNode *l = build_linkedlist<int>({4, 2, 1, 3});
    Solution s;
    ListNode *res = s.insertionSortList(l);
    cout << res << endl;
    return 0;
}
