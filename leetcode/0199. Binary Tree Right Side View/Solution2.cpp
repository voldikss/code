#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

#define TreeNode TreeNode<int>

class Solution {
  public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* head;

        while (!q.empty()) {
            // 先把最后一个元素保存进结果
            res.push_back(q.back()->val);
            // 弹出当前层，装入下一层
            for (int size = q.size(), i = 0; i < size; ++i) {
                TreeNode* head = q.front();
                q.pop();

                if (head->left) q.push(head->left);
                if (head->right) q.push(head->right);
            }
        }
        return res;
    }
};
