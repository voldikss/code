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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<TreeNode *>> cache(n + 1, vector<TreeNode *>());
        cache[0].push_back(nullptr);
        cache[1].push_back(new TreeNode(1));
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                for (auto l : cache[j - 1]) {
                    for (auto r : cache[i - j]) {
                        TreeNode *node = new TreeNode(j);
                        if (l)
                            node->left = new TreeNode(l->val, l->left, l->right);
                        if (r) node->right = this->copy_and_increase(r, j);
                        cache[i].push_back(node);
                    }
                }
            }
        }
        return cache[n];
    }

    TreeNode *copy_and_increase(TreeNode *node, int val) {
        if (!node) return nullptr;
        TreeNode *newNode = new TreeNode(node->val + val);
        newNode->left = this->copy_and_increase(node->left, val);
        newNode->right = this->copy_and_increase(node->right, val);
        return newNode;
    }
};

int main() {
    Solution s;
    auto res = s.generateTrees(3);
    cout << res << endl;
    return 0;
}
