#include "../../include/global.hpp"
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

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        if (head->next && head->val == head->next->val) {
            while (head->next && head->val == head->next->val) head = head->next;
            return this->deleteDuplicates(head->next);
        } else {
            head->next = this->deleteDuplicates(head->next);
        }
        return head;
    }
};

int main() {
    Solution s;
    return 0;
}
