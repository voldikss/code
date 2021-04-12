#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        map<TreeNode*, bool> visited;
        TreeNode* p = nullptr;
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
