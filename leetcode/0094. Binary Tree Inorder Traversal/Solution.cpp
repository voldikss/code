#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        this->visit(root, res);
        return res;
    }

    void visit(TreeNode* root, vector<int>& res) {
        if (!root) return;
        this->visit(root->left, res);
        res.push_back(root->val);
        this->visit(root->right, res);
    }
};

int main() {
    Solution s;
    vector<variant<int, nullptr_t>> tree_nodes = {1, nullptr, 2, 3};
    TreeNode* tree = build_binary_tree(tree_nodes);
    // print_ascii_tree(tree);
    cout << s.inorderTraversal(tree) << endl;
}
