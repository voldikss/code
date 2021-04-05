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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque<TreeNode *> q;
        q.emplace_back(root);
        bool flag = true;
        while (!q.empty()) {
            vector<int> tmp;
            int n = q.size();
            while (n--) {
                TreeNode *node;
                if (flag) {
                    node = q.front();
                    q.pop_front();
                    if (node->left)
                        q.emplace_back(node->left);
                    if (node->right)
                        q.emplace_back(node->right);
                } else {
                    node = q.back();
                    q.pop_back();
                    if (node->right)
                        q.emplace_front(node->right);
                    if (node->left)
                        q.emplace_front(node->left);
                }
                tmp.emplace_back(node->val);
            }
            flag = !flag;
            res.emplace_back(tmp);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<variant<int, nullptr_t>> nodes = {1, 3, 2, 4, 5, 6, 7, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    TreeNode *tree = build_binary_tree<int>(nodes);
    auto res = s.zigzagLevelOrder(tree);
    cout << res << endl;
    return 0;
}
