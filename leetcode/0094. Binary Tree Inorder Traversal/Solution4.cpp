#include "../../vital/binary_tree.cpp"
#include "../../vital/vector.cpp"
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

// Most common algorithm for inorderTraversal
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *p = root;
        stack<TreeNode *> st;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            res.emplace_back(p->val);
            p = p->right;
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