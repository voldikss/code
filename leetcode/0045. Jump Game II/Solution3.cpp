#include "../../include/global.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
using namespace std;

class Solution {
  public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        int dp[len];
        dp[0] = 0;
        dp[1] = 1;
        int j = 0;
        for (int i = 1; i < len; i++) {
            while (j < i) {
                if (nums[j] + j >= i) {
                    dp[i] = dp[j] + 1;
                    break;
                }
                j++;
            }
        }
        return dp[len - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    // auto nums = vector<int>{2, 3, 1, 1, 4};
    auto nums = vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};
    // auto nums = vector<int>{2, 3, 1, 1, 4};
    // auto nums = vector<int>{5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    // auto nums = vector<int>{2, 3, 0, 1, 4};
    auto res = s.jump(nums);
    cout << "res: " << res << endl;
    return 0;
}
