#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        stack<int> s;
        int second = INT32_MIN;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < second) return true;
            while (!s.empty() && nums[i] > s.top()) {
                second = max(s.top(), second);
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> input = {3, 1, 4, 2};
    Solution s;
    bool res = s.find132pattern(input);
    cout << res << endl;
    return 0;
}
