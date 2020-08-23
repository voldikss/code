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

// Definition for a Node.
class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;
        map<Node *, Node *> old2new;

        Node *dummy = new Node(0);
        Node *p = dummy;
        while (head) {
            if (old2new[head] != nullptr) {
                p->next = old2new[head];
            } else {
                p->next = new Node(head->val);
                old2new[head] = p->next;
            }

            if (head->random != nullptr) {
                if (old2new[head->random] != nullptr) {
                    p->next->random = old2new[head->random];
                } else {
                    p->next->random = new Node(head->random->val);
                    old2new[head->random] = p->next->random;
                }
            }

            head = head->next;
            p = p->next;
        }
        return dummy->next;
    }
};

int main() {

    return 0;
}
