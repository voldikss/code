#include "../../include/binary_tree.hpp"
#include "../../include/linkedlist.hpp"
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
#include <variant>
#include <vector>
using namespace std;

#define TreeNode TreeNode<int>
#define ListNode ListNode<int>

class Solution {
  public:
    TreeNode* sortedListToBST(ListNode* head) {
        return this->helper(head, nullptr);
    }

  private:
    TreeNode* helper(ListNode* begin, ListNode* end) {
        if (begin == end) return nullptr;
        ListNode* faster = begin;
        ListNode* slower = begin;
        while (true) {
            faster = faster->next;
            if (faster == end) break;
            faster = faster->next;
            if (faster == end) break;
            slower = slower->next;
        }
        TreeNode* node = new TreeNode(slower->val);
        node->left = this->helper(begin, slower);
        node->right = this->helper(slower->next, end);
        return node;
    }
};

int main() {
    Solution s;
    vector<int> nodes = {-10, -3, 0, 5, 9};
    ListNode* list = build_linkedlist(nodes);
    auto res = s.sortedListToBST(list);
    cout << res << endl;
    return 0;
}
