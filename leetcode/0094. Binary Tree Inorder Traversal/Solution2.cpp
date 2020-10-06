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

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            if (node->left) {
                st.push(node->left);
            } else {
                st.pop();
                if (!st.empty())
                    st.top()->left = nullptr;
                res.push_back(node->val);
                if (node->right) st.push(node->right);
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
