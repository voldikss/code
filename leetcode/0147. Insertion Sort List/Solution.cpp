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

// 超时。。。
class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *new_head = new ListNode;
        new_head->next = head;
        ListNode *p = new_head;
        while (p->next) {
            ListNode *pp = new_head;
            ListNode *Next = p->next;
            while (pp != p) {
                if (pp->next->val > p->next->val) {
                    Next = p->next;
                    if (pp->next == p) {
                        pp->next = p->next;
                        p->next = pp->next->next;
                        pp->next->next = p;
                    } else {
                        ListNode *tmp1 = pp->next->next;
                        ListNode *tmp2 = p->next->next;
                        pp->next->next = tmp2;
                        p->next->next = tmp1;
                        ListNode *tmp = pp->next;
                        pp->next = p->next;
                        p->next = tmp;
                    }
                    break;
                }
                pp = pp->next;
            }
            p = Next;
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
