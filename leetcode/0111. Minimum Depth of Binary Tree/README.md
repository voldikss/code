此题使用队列的方法实在是最为直观不过的了

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            ++res;
            for (int i = q.size(); i > 0; --i) {
                auto t = q.front(); q.pop();
                if (!t->left && !t->right) return res;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return -1;
    }
};
```
