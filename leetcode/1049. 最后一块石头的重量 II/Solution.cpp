#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int lastStoneWeightII(vector<int>& stones) {
        int len = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        cout << "target: " << target << endl;

        vector<vector<int>> dp(len + 1, vector<int>(target + 1, 0));
        for (int j = target; j >= stones[0]; j--) {
            dp[0][j] = stones[0];
        }
        for (int i = 1; i < len; i++) {
            for (int j = 1; j <= target; j++) {
                if (j < stones[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            }
        }

        return (sum - dp[len - 1][target]) - dp[len - 1][target];
    }
};

int main(int argc, char** argv) {

    return 0;
}
