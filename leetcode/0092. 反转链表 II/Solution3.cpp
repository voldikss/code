#include "../../include/linkedlist.cpp"
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

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == nullptr) return head;
        // TODO 双指针做法
    }

    int main(int argc, char** argv) {
        Solution s;
        auto head = build_linkedlist({1, 2, 3, 4, 5, 6, 7, 8});
        int left = 3, right = 6;
        // auto head = build_linkedlist({1, 2, 3, 4, 5});
        // int left = 2, right = 4;
        auto res = s.reverseBetween(head, left, right);
        cout << res << endl;
        return 0;
    }
}
