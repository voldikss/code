#include "../../include/binary_tree.hpp"
#include "../../include/vector.hpp"
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
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        this->visit(root, res);
        return res;
    }

    void visit(TreeNode *root, vector<int> &res) {
        if (!root) return;
        this->visit(root->left, res);
        res.push_back(root->val);
        this->visit(root->right, res);
    }
};

int main() {
    Solution s;
    vector<variant<int, nullptr_t>> tree_nodes = {1, nullptr, 2, 3};
    TreeNode *tree = build_binary_tree(tree_nodes);
    // print_ascii_tree(tree);
    cout << s.inorderTraversal(tree) << endl;
}
