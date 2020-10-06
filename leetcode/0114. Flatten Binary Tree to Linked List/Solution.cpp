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
    void flatten(TreeNode *root) {
        if (!root) return;
        TreeNode *p = root->left;
        while (p && p->right) p = p->right;
        if (p) {
            p->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        flatten(root->right);
    }
};

int main() {
    Solution s;
    vector<variant<int, nullptr_t>> nodes = {1, nullptr, 2, 3, nullptr};
    TreeNode *tree = build_binary_tree(nodes);
    s.flatten(tree);
    cout << tree << endl;
    return 0;
}
