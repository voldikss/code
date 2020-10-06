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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode *> st;
        map<TreeNode *, bool> visited;
        TreeNode *p = nullptr;
        st.push(root);
        while (!st.empty()) {
            p = st.top();
            if (!visited[p]) {
                if (p->right) st.push(p->right);
                if (p->left) st.push(p->left);
                visited[p] = true;
            } else {
                st.pop();
                res.push_back(p->val);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
