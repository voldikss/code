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
#include <variant>
#include <vector>
using namespace std;

#define TreeNode TreeNode<int>

class Solution {
    long pre = INT64_MIN;

  public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        if (!this->isValidBST(root->left)) return false;
        if (root->val <= pre) return false;
        pre = root->val;
        if (!this->isValidBST(root->right)) return false;
        return true;
    }
};

int main() {
    Solution s;
    // vector<variant<int, nullptr_t>> nodes = {};
    // vector<variant<int, nullptr_t>> nodes = {2, 1, 3, nullptr, nullptr};
    vector<variant<int, nullptr_t>> nodes = {5, 1, 4, nullptr, nullptr, 3, 6, nullptr, nullptr, nullptr, nullptr};
    TreeNode *tree = build_binary_tree(nodes);
    cout << s.isValidBST(tree) << endl;
    return 0;
}
