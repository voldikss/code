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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;
        this->helper(root, res, path, sum);
        return res;
    }

  private:
    void helper(TreeNode *node, vector<vector<int>> &res, vector<int> &path, int sum) {
        if (!node) return;
        sum -= node->val;
        path.emplace_back(node->val);
        if (!node->left && !node->right && sum == 0) {
            res.emplace_back(vector<int>(path));
            path.pop_back();
            return;
        }

        this->helper(node->left, res, path, sum);
        this->helper(node->right, res, path, sum);
        path.pop_back();
    }
};

int main() {

    return 0;
}
