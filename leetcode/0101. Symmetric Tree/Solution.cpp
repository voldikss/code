#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return this->isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val != q->val) && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};

int main() {

    return 0;
}
