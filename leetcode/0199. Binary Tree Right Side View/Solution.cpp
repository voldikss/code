#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int depth, vector<int>& res) {
        if (root == NULL) return;
        if (res.size() == depth) {
            res.push_back(root->val);
        }

        dfs(root->right, depth + 1, res);
        dfs(root->left, depth + 1, res);
    }
};
