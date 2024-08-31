#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        int i = 0, j = 0, di = 0, dj = 1;
        for (int x = 0; x < n * n; x++) {
            res[i][j] = x + 1;
            if (res[(i + di + n) % n][(j + dj + n) % n] != -1) {
                swap(di, dj);
                dj = -dj;
            }
            i += di;
            j += dj;
        }
        return res;
    }
};

int main() {
    Solution s;
    auto res = s.generateMatrix(3);
    // cout << res << endl;
    for (int n = 1; n <= 10; n++) {
        auto res = s.generateMatrix(n);
        cout << res << endl;
    }
    return 0;
}
