#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != slow) {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main() {

    return 0;
}
