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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return this->isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val != q->val) && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};

int main() {

    return 0;
}
