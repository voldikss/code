#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

// 尝试失败，貌似无解
class Solution {
  public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        stack<int> s;
        int first = INT8_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > first && !s.empty() && nums[i] < s.top()) return true;
            first = min(first, nums[i]);
            while (!s.empty() && nums[i] < s.top()) {
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

int main() {
    // vector<int> input = {3, 1, 4, 2}; // 1
    // vector<int> input = {4, 1, 3, 2}; // 1
    // vector<int> input = {3, 4, 1, 2}; // 0
    // vector<int> input = {-2,1,1};     // 0
    // vector<int> input = {-2, 1, -2};  // 0
    // vector<int> input = {319, 572, 68, 456, 3, 547, 507, 758, 225, 402};
    vector<int> input = {3, 5, 0, 3, 4};
    Solution s;
    bool res = s.find132pattern(input);
    cout << res << endl;
    return 0;
}
