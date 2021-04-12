#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mm(m, 1);
        vector<int> nn(n, 1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    mm[i] = 0;
                    nn[j] = 0;
                }
            }
        }
        // cout << matrix << endl;

        for (int i = 0; i < m; i++) {
            if (mm[i] == 0) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        // cout << matrix << endl;

        for (int j = 0; j < n; j++) {
            if (nn[j] == 0) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution s;
    // vector<vector<int>> matrix = {
    //     {1, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 1}};
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};
    s.setZeroes(matrix);
    cout << matrix << endl;
    return 0;
}
