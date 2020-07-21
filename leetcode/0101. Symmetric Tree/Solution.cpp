#include "../../vital/binary_tree.cpp"
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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return this->isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (!p || !q) return !p && !q;
        if (p->val != q->val) return false;
        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};

int main() {

    return 0;
}
