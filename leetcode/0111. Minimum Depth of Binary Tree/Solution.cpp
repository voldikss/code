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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left && right) ? 1 + min(left, right) : 1 + left + right;
    }
};

int main() {

    return 0;
}
