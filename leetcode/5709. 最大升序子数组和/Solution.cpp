#include "../../include/global.hpp"
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
    int maxAscendingSum(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];

        for (int i = 1; i < len; i++) {
            dp[i] = nums[i];
            if (nums[i] > nums[i - 1])
                dp[i] += dp[i - 1];
            // for (int j = i - 1; j >= 0; j--) {
            //     if (nums[i] > nums[j]) {
            //         dp[i] += dp[j];
            //         break;
            //     }
            // }
        }

        cout << dp << endl;

        return *max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<int> nums{5, 5, 6, 6, 6, 9, 1, 2};
    vector<int> nums{10, 20, 30, 5, 10, 50};
    auto res = s.maxAscendingSum(nums);
    return res;
    return 0;
}
