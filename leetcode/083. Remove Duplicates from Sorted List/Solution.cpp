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

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new ListNode(head->val);
        ListNode *res = new ListNode(head->val);
        ListNode *q = res;
        ListNode *p2 = head->next;
        ListNode *p1 = head;
        while (p1 != NULL) {
            if (p1->val != q->val) {
                q->next = new ListNode(p1->val);
                q = q->next;
                p1 = p1->next;
            } else {
                p1 = p1->next;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
