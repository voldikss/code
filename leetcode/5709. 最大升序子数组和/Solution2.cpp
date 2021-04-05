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
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                if (i == j || nums[j] > nums[j - 1]) {
                    cur += nums[j];
                } else {
                    break;
                }
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<int> nums{5, 5, 6, 6, 6, 9, 1, 2};
    vector<int> nums{10, 20, 30, 5, 10, 50};
    auto ans = s.maxAscendingSum(nums);
    cout << ans << endl;
    return 0;
}
