#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        return this->helper(inorder, postorder);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return nullptr;

        TreeNode* node = new TreeNode(postorder[0]);
        if (postorder.size() == 1) return node;

        int i;
        for (i = 0; i < inorder.size(); i++)
            if (inorder[i] == postorder[0]) break;

        vector<int> leftInOrder = vector<int>(inorder.begin(), inorder.begin() + i);
        vector<int> rightInOrder = vector<int>(inorder.begin() + i + 1, inorder.end());

        vector<int> leftPostOrder = vector<int>(postorder.end() - i, postorder.end());
        vector<int> rightPostOrder = vector<int>(postorder.begin() + 1, postorder.end() - i);

        node->left = this->helper(leftInOrder, leftPostOrder);
        node->right = this->helper(rightInOrder, rightPostOrder);
        return node;
    }
};

int main() {
    Solution s;
    // vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    auto res = s.buildTree(inorder, postorder);
    cout << res << endl;
    return 0;
}
