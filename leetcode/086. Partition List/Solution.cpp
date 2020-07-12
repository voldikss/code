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
    ListNode *partition(ListNode *head, int x) {
        // l: less; ge: greater_equal
        // l_p: pointer of less; ge_p: pointer of greater_equal
        ListNode *l = new ListNode(-1);
        ListNode *l_p = l;
        ListNode *ge = new ListNode(-1);
        ListNode *ge_p = ge;
        while (head) {
            if (head->val < x) {
                l_p->next = head;
                l_p = l_p->next;
            } else {
                ge_p->next = head;
                ge_p = ge_p->next;
            }
            head = head->next;
        }
        ge_p->next = nullptr;
        l_p->next = ge->next;
        return l->next;
    }
};

int main() {
    Solution s;
    vector<int> input = {1, 4, 3, 2, 5, 2};
    int x = 3;

    ListNode *head = new ListNode(-1);
    ListNode *p = head;
    for (auto x : input) {
        p->next = new ListNode(x);
        p = p->next;
    }
    p->next = nullptr;
    head = head->next;

    auto res = s.partition(head, x);
    cout << res << endl;
    return 0;
}
