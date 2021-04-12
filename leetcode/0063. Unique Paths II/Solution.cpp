#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++)
            if (obstacleGrid[0][i] == 0)
                for (int j = i; j < n; j++) obstacleGrid[0][j] = 0;
        for (int i = 0; i < m; i++)
            if (obstacleGrid[i][0] == 0)
                for (int j = i; j < m; j++) obstacleGrid[j][0] = 0;

        // cout << obstacleGrid << endl;
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    // vector<vector<int>> obstacleGrid = {{0}};
    // vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> obstacleGrid = {{0, 0}, {1, 1}, {0, 0}};
    auto res = s.uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    return 0;
}
