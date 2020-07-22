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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;
        return this->hasPathSum(root->left, sum - root->val) || this->hasPathSum(root->right, sum - root->val);
    }
};

int main() {

    return 0;
}
