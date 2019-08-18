#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {
  }
};

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    dfs(root, 0, res);
    return res;
  }

  void dfs(TreeNode *root, int depth, vector<int> &res) {
    if (root == NULL) return;
    if (res.size() == depth) {
      res.push_back(root->val);
    }

    dfs(root->right, depth + 1, res);
    dfs(root->left, depth + 1, res);
  }
};
