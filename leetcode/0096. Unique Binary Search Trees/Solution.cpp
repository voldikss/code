#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    // cout << s.numTrees(3) << endl;
    cout << s.numTrees(4) << endl;
    return 0;
}
