#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            vector<int> tmp;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                tmp.emplace_back(node->val);

                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<variant<int, nullptr_t>> nodes = {3, 9, 20, nullptr, nullptr, 15, 7};
    TreeNode* tree = build_binary_tree(nodes);
    cout << s.levelOrder(tree) << endl;
    return 0;
}
