#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        /*这个判断逻辑不好看*/
        // if (t1 && t2) {
        //   t1->val += t2->val;
        //   t1->left = mergeTrees(t1->left, t2->left);
        //   t1->right = mergeTrees(t1->right, t2->right);
        //   return t1;
        // } else if (t1)
        //   return t1;
        // else if (t2)
        //   return t2;
        // else
        //   return NULL;

        /*这个好看多了*/
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
