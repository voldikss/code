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

template <typename T>
ostream &operator<<(ostream &os, const list<T> &l) {
    for (auto &i : l) os << i << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto x : vec) os << x << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vec) {
    for (auto &x : vec) os << x << endl;
    return os;
}

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

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode *save_head = head;
        ListNode *p = head;
        ListNode *q = p->next;
        ListNode *r = q->next;
        while (q) {
            q->next = p;
            if (!r) break;
            p = q;
            q = r;
            r = r->next;
        }
        save_head->next = nullptr;
        return q;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    vector<int> nodes = {1, 2, 3, 4, 5};
    for (auto x : nodes) {
        ListNode *node = new ListNode(x);
        p->next = node;
        p = p->next;
    }
    p->next = nullptr;

    auto res = s.reverseList(head->next);
    cout << res << endl;
    return 0;
}
