#include "../../include/global.hpp"
#include <algorithm>
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

// 佟湘玉：把我都给气笑咧。。。
class Solution {
  public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        cout << dp << endl;

        int maxlength = *max_element(dp.begin(), dp.end());
        int i = len - 1;
        while (i >= 0) {
            if (dp[i] == maxlength) break;
            i--;
        }
        int idx_of_2 = 0;
        while (idx_of_2 < len) {
            if (dp[idx_of_2] == 2) break;
            idx_of_2++;
        }
        vector<int> count(len + 1, 0);
        while (i >= 0) {
            cout << "ddd" << dp[i] << endl;
            if (dp[i] == 1) {
                if (i > idx_of_2) {
                    i--;
                    continue;
                }
                if (maxlength >= 2 && nums[i] >= nums[idx_of_2]) {
                    cout << nums[i] << endl;
                    break;
                }
                count[dp[i]]++;
            } else if (dp[i] == maxlength - 1) {
                count[dp[i]]++;
                maxlength--;
            } else if (dp[i] == maxlength) {
                count[dp[i]]++;
            }
            i--;
        }

        cout << count << endl;

        int res = 1;
        for (const auto& x : count) {
            if (x != 0) res *= x;
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
    vector<int> nums{1,2,4,3,5,4,7,2};   // 
    // vector<int> nums{4, 10, 4};   // 1
    auto res = s.findNumberOfLIS(nums);
    cout << res << endl;
    return 0;
}
