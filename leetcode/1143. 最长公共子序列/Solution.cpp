#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        if (n1 == 0 || n2 == 0) return 0;
        vector<vector<int>> dp(n1, vector<int>(n2));
        for (int i = 0; i < n1; i++) {
            if (text1[i] == text2[0]) {
                for (int j = i; j < n1; j++) {
                    dp[j][0] = 1;
                }
                break;
            }
        }
        for (int i = 0; i < n2; i++) {
            if (text2[i] == text1[0]) {
                for (int j = i; j < n2; j++) {
                    dp[0][j] = 1;
                }
                break;
            }
        }
        for (int i = 1; i < n1; i++) {
            for (int j = 1; j < n2; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n1 - 1][n2 - 1];
    }
};

int main(int argc, char** argv) {

    return 0;
}
