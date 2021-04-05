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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode *node = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return node;

        int i;
        for (i = 0; i < inorder.size(); i++)
            if (inorder[i] == preorder[0]) break;

        // left
        vector<int> leftPreOrder = vector<int>(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> leftInOrder = vector<int>(inorder.begin(), inorder.begin() + i);
        node->left = this->buildTree(leftPreOrder, leftInOrder);

        // right
        vector<int> rightPreOrder = vector<int>(preorder.begin() + i + 1, preorder.end());
        vector<int> rightInOrder = vector<int>(inorder.begin() + i + 1, inorder.end());
        node->right = this->buildTree(rightPreOrder, rightInOrder);
        return node;
    }
};

int main() {
    Solution s;
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    auto res = s.buildTree(preorder, inorder);
    cout << res << endl;
    return 0;
}
