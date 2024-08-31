#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1);
        vector<int> count(len, 1);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int max_len = *max_element(dp.begin(), dp.end());
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (dp[i] == max_len) {
                res += count[i];
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<int> nums{1, 3, 5, 4, 7};   // 2
    // vector<int> nums{1};
    // vector<int> nums{2, 2, 2, 2, 2}; // 5
    // vector<int> nums{5, 4, 9, 8};   // 4
    // vector<int> nums{9, 3, 4, 1, 0, 5};   // 1
    // vector<int> nums{8, 4, 0, 4, 3, 9, 10, 3, 4};   // 2
    // vector<int> nums{1, 2, 4, 3, 5, 4, 7, 2};   //
    vector<int> nums{1, 2, 3, 1, 2, 3, 1, 2, 3};   //
    // vector<int> nums{4, 10, 4};   // 1
    auto res = s.findNumberOfLIS(nums);
    cout << res << endl;
    return 0;
}
