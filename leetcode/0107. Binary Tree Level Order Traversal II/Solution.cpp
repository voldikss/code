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

class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            while (n--) {
                TreeNode *node = q.front();
                q.pop();
                tmp.emplace_back(node->val);
                res.emplace_back(tmp);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
