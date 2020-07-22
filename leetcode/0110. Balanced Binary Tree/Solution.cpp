#include "../../vital/binary_tree.cpp"
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

class Solution {
  public:
    map<TreeNode *, int> cache;
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode *node) {
        if (!node) return 1;
        if (cache.count(node)) return cache[node];
        int depth = max(this->depth(node->left), this->depth(node->right)) + 1;
        cache.insert({node, depth});
        return depth;
    }
};

int main() {

    return 0;
}
