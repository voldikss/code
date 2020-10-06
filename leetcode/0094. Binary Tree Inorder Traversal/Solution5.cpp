#include "../../include/binary_tree.cpp"
#include "../../include/vector.cpp"
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

// Mirros algorithm
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *p = root;
        while (root) {
            if (root->left) {
                p = root->left;
                while (p->right) {
                    p = p->right;
                }
                p->right = root;
                TreeNode *tmp = root;
                root = root->left;
                tmp->left = nullptr;
            } else {
                res.emplace_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<variant<int, nullptr_t>> tree_nodes = {1, nullptr, 2, 3};
    TreeNode *tree = build_binary_tree(tree_nodes);
    // print_ascii_tree(tree);
    cout << s.inorderTraversal(tree) << endl;
}
