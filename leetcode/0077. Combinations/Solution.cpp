#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        this->dfs(n, k, 1, {}, res);
        return res;
    }

    void dfs(int n, int k, int start, vector<int> path, vector<vector<int>>& res) {
        if (path.size() > k) return;

        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i + 1, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    cout << s.combine(4, 2) << endl;
    return 0;
}
