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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *res = new ListNode(head->val);
        ListNode *q = res;
        ListNode *p = head->next;
        while (p != NULL) {
            if (p->val != q->val) {
                q->next = new ListNode(p->val);
                q = q->next;
                p = p->next;
            } else {
                p = p->next;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
