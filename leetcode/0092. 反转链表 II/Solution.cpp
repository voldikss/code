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
#include <vector>
using namespace std;

#define ListNode ListNode<int>

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == nullptr) return head;
        ListNode* dammy = new ListNode;
        dammy->next = head;
        int index = 0;
        ListNode* p = dammy;
        while (index + 1 < left) {
            p = p->next;
            index++;
        }
        p->next = this->reverse(p->next, index, right)[0];
        return dammy->next;
    }

    // 第一个数存储链头，第二个存储链尾（因为要将整体前的一个节点链接到尾部）
    // 大概没有人采用和我一样这么智障和好笑的做法了
    vector<ListNode*> reverse(ListNode* head, int index, int right) {
        if (index + 1 < right) {
            vector<ListNode*> node = this->reverse(head->next, index + 1, right);
            head->next = node[1]->next;
            node[1]->next = head;
            node[1] = head;
            return node;
        } else {
            return {head, head};
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    // auto head = build_linkedlist({1, 2, 3, 4, 5, 6, 7, 8});
    // int left = 3, right = 6;
    auto head = build_linkedlist<int>({1, 2, 3, 4, 5});
    int left = 2, right = 4;
    auto res = s.reverseBetween(head, left, right);
    cout << res << endl;
    return 0;
}
