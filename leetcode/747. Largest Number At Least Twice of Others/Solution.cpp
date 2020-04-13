//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
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
    int dominantIndex(vector<int> &nums) {
        int idx = 0;
        int maxValue = -1;
        int secondMaxValue = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                idx = i;
                secondMaxValue = maxValue;
                maxValue = nums[i];
            } else if (nums[i] > secondMaxValue) {
                secondMaxValue = nums[i];
            }
        }
        // cout << maxValue << endl;
        // cout << secondMaxValue << endl;
        if (maxValue >= 2 * secondMaxValue) {
            return idx;
        } else {
            return -1;
        }
    }
};

int main() {
    // vector<int> nums = {3, 6, 1, 0};
    // vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {2};
    Solution s;
    int ans = s.dominantIndex(nums);
    cout << ans << endl;
    return 0;
}
