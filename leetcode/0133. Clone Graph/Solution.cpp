#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> old2new;
        return dfs(node, old2new);
    }

    Node* dfs(Node* node, map<Node*, Node*>& old2new) {
        if (!node) return nullptr;
        Node* newNode = new Node(node->val);
        if (node->neighbors.empty()) return newNode;
        old2new[node] = newNode;   // dont use old2new.insert({node, newNode}) !!!

        for (auto n : node->neighbors) {
            if (old2new[n]) {
                newNode->neighbors.push_back(old2new[n]);
            } else {
                newNode->neighbors.push_back(this->dfs(n, old2new));
            }
        }

        return newNode;
    }
};

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);

    Solution s;
    s.cloneGraph(n1);
    return 0;
}
