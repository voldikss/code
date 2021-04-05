#include "../../include/global.hpp"
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        int pre = 1;
        int cur = 0;
        vector<int> tmp;
        while (!q.empty()) {
            TreeNode *node = q.front();
            tmp.emplace_back(node->val);

            if (node->left) {
                q.push(node->left);
                cur++;
            }

            if (node->right) {
                q.push(node->right);
                cur++;
            }

            q.pop();
            pre--;

            if (pre == 0) {
                res.emplace_back(tmp);
                tmp.clear();
                pre = cur;
                cur = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<variant<int, nullptr_t>> nodes = {3, 9, 20, nullptr, nullptr, 15, 7};
    TreeNode *tree = build_binary_tree(nodes);
    cout << s.levelOrder(tree) << endl;
    return 0;
}
