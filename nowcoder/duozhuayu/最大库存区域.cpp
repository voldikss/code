#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最大库区的分类数字
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int categoryOfMaxWarehouseArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                int size = dfs(grid, i, j, grid[i][j]);
                res[grid[i][j]] = max(res[grid[i][j]], size);
            }
        }

        int maxkey = 0;
        int maxval = 0;
        for (const auto x : res) {
            if (x.second > maxval) {
                maxkey = x.first;
                maxval = x.second;
            }
        }
        // cout << res << endl;
        return maxkey;
    }

    int dfs(const vector<vector<int>>& grid, int r, int c, int val) {
        int m = grid.size();
        int n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n) return 0;
        if (grid[r][c] != val) return 0;
        if (visited[r][c]) return 0;
        visited[r][c] = true;
        return dfs(grid, r - 1, c, val) +
               dfs(grid, r + 1, c, val) +
               dfs(grid, r, c - 1, val) +
               dfs(grid, r, c + 1, val) + 1;
    }

  private:
    unordered_map<int, int> res;
    bool visited[32][32] = {0};
};

int main(int argc, char** argv) {
    Solution s;
    // vector<vector<int>> grid{{1, 3, 1, 2},
    //                          {2, 1, 2, 2},
    //                          {3, 2, 3, 3}};
    vector<vector<int>> grid{{1, 1, 1, 2},
                             {2, 1, 2, 2},
                             {3, 2, 3, 3}};
    auto res = s.categoryOfMaxWarehouseArea(grid);
    cout << res << endl;
    return 0;
}
