#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

// Mirros algorithm
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode* p = root;
        while (root) {
            if (root->left) {
                p = root->left;
                while (p->right) {
                    p = p->right;
                }
                p->right = root;
                TreeNode* tmp = root;
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
    TreeNode* tree = build_binary_tree(tree_nodes);
    // print_ascii_tree(tree);
    cout << s.inorderTraversal(tree) << endl;
}
