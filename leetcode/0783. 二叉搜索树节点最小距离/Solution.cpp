#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  private:
    int mindiff = INT_MAX;
    TreeNode* prev = nullptr;

  public:
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        return mindiff;
    }

    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        if (prev) {
            mindiff = min(mindiff, root->val - prev->val);
        }
        prev = root;
        traverse(root->right);
    }
};

int main(int argc, char** argv) {

    return 0;
}
