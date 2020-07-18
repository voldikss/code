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
        if (!head || !head->next) return head;
        ListNode *res = new ListNode(-1);
        ListNode *q = res;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2) {
            if (p1->val != p2->val) {
                q->next = new ListNode(p1->val);
                q = q->next;
                p1 = p1->next;
                p2 = p2->next;
            } else {
                while (p1 && p1->val == p2->val) p1 = p1->next;
                if (p1 && p1->next)
                    p2 = p1->next;
                else
                    p2 = NULL;
            }
            if (p1 && p1->next == NULL)
                if (q->val != p1->val) q->next = p1;
        }
        return res->next;
    }
};

int main() {
    Solution s;
    return 0;
}
