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
        while (head->next && head->val == head->next->val) head = head->next;
        head->next = this->deleteDuplicates(head->next);
        return head;
    }
};

int main() {

    return 0;
}
