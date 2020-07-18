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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x), next(NULL) {
    }
};

ostream &operator<<(ostream &os, const ListNode *head) {
    while (head) {
        os << head->val << " ";
        head = head->next;
    }
    return os;
}

// build a linkedlist from vector of integers
ListNode *buildList(const vector<int> &nodes) {
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    for (auto x : nodes) {
        ListNode *node = new ListNode(x);
        p->next = node;
        p = p->next;
    }
    p->next = nullptr;
    return head->next;
}
