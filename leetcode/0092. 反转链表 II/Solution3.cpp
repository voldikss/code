#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == nullptr) return head;
        ListNode* dammy = new ListNode;
        dammy->next = head;
        ListNode* p1 = dammy;
        int index = 1;
        while (index < left) {
            p1 = p1->next;
            index++;
        }

        ListNode* p2 = p1->next;
        while (index < right) {
            ListNode* tmp = p1->next;
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = tmp;
            index++;
        }

        // cout << dammy->next << endl;
        return dammy->next;
    };
};

int main(int argc, char** argv) {
    Solution s;
    auto head = build_linkedlist<int>({1, 2, 3, 4, 5, 6, 7, 8});
    int left = 3, right = 6;
    // auto head = build_linkedlist({1, 2, 3, 4, 5});
    // int left = 2, right = 4;
    auto res = s.reverseBetween(head, left, right);
    cout << res << endl;
    return 0;
}
