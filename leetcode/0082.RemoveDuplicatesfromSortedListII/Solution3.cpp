#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode dammy;
        dammy.next = head;
        ListNode* cur = &dammy;
        while (cur && cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int val = cur->next->val;
                while (cur->next && cur->next->val == val) {
                    auto tmp = cur->next;
                    cur->next = tmp->next;
                    delete tmp;
                }
            } else {
                cur = cur->next;
            }
        }
        return dammy.next;
    }
};

int main(int argc, char** argv) {

    return 0;
}
