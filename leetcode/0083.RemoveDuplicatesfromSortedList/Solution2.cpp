#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        while (head->next && head->val == head->next->val) head = head->next;
        head->next = this->deleteDuplicates(head->next);
        return head;
    }
};

int main() {

    return 0;
}
