#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<int> curr(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                curr[j] += curr[j - 1];
            }
        return curr[n - 1];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(7, 3) << endl;
    return 0;
}
