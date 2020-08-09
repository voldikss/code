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
    int res = 0;

  public:
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        this->visit(root);
        return this->res;
    }

    void visit(TreeNode *root) {
        if (root->left) {
            root->left->val += 10 * root->val;
            this->visit(root->left);
        }
        if (root->right) {
            root->right->val += 10 * root->val;
            this->visit(root->right);
        }
        if (!root->left && !root->right) {
            this->res += root->val;
        }
    }
};

int main() {
    vector<variant<int, nullptr_t>> nodes = {4, 9, 0, 5, 1};
    TreeNode *tree = build_binary_tree(nodes);

    Solution s;
    auto res = s.sumNumbers(tree);
    cout << res << endl;
    return 0;
}
