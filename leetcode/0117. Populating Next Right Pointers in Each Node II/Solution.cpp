#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
  public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {
    }

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// 使用队列逐行进行，但是使用了额外的空间不符题意
class Solution {
  public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node*> q;
        int i;
        Node* node;
        q.push(root);
        while (!q.empty()) {
            for (int size = q.size(), i = 0; i < size; ++i) {
                node = q.front();
                q.pop();
                if (i == size - 1) {
                    node->next = nullptr;
                } else {
                    node->next = q.front();
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};
