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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        return this->helper(1, n);
    }

    vector<TreeNode *> helper(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.emplace_back(nullptr);
            return res;
        }

        if (start == end) {
            res.emplace_back(new TreeNode(start));
            return res;
        }

        for (int i = start; i <= end; i++) {
            auto leftTrees = this->helper(start, i - 1);
            auto rightTrees = this->helper(i + 1, end);
            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode *node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.emplace_back(node);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    auto res = s.generateTrees(3);
    cout << res << endl;
    return 0;
}
