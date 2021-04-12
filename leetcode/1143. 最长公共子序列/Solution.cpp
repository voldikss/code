#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

// 这也太蠢了
// class Solution {
//   public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
//         if (n1 == 0 || n2 == 0) return 0;
//         vector<vector<int>> dp(n1, vector<int>(n2));
//         for (int i = 0; i < n1; i++) {
//             if (text1[i] == text2[0]) {
//                 for (int j = i; j < n1; j++) {
//                     dp[j][0] = 1;
//                 }
//                 break;
//             }
//         }
//         for (int i = 0; i < n2; i++) {
//             if (text2[i] == text1[0]) {
//                 for (int j = i; j < n2; j++) {
//                     dp[0][j] = 1;
//                 }
//                 break;
//             }
//         }
//         for (int i = 1; i < n1; i++) {
//             for (int j = 1; j < n2; j++) {
//                 if (text1[i] == text2[j]) {
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 } else {
//                     dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//                 }
//             }
//         }
//         return dp[n1 - 1][n2 - 1];
//     }
// };

class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        if (n1 == 0 || n2 == 0) return 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));   // n1+1 and n2+1 !!! 刷了这么些题还是不知道用这个 trick
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

int main(int argc, char** argv) {

    return 0;
}
