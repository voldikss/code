#include "../../include/binary_tree.cpp"
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
    int maxDepth(TreeNode *root) {
        return this->maxDepth(root, 0);
    }

    int maxDepth(TreeNode *node, int depth) {
        if (!node) return depth;
        return max(this->maxDepth(node->left, depth + 1), this->maxDepth(node->right, depth + 1));
    }
};

int main() {

    return 0;
}
