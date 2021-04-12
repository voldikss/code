#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        TreeNode* p = nullptr;
        st.push(root);
        while (!st.empty()) {
            p = st.top();
            res.push_back(p->val);
            st.pop();
            if (p->right) st.push(p->right);
            if (p->left) st.push(p->left);
        }
        return res;
    }
};

int main() {

    return 0;
}
