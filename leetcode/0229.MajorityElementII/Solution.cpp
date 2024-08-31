#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        if (nums.size() == 1) {
            for (int n : nums) res.push_back(n);
            return res;
        }
        int major1;
        int major2;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int n : nums) {
            if (major1 == n) {
                cnt1++;
            } else if (major2 == n) {
                cnt2++;
            } else if (cnt1 == 0) {
                major1 = n;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                major2 = n;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int n : nums) {
            if (n == major1) {
                cnt1++;
            } else if (n == major2) {
                cnt2++;
            }
        }

        // cout << major1 << " " << cnt1 << endl;
        // cout << major2 << " " << cnt2 << endl;

        if (cnt1 > nums.size() / 3) {
            res.push_back(major1);
        }
        if (cnt2 > nums.size() / 3) {
            res.push_back(major2);
        }
        return res;
    }
};

int main() {
    // vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    // vector<int> nums = {3, 0, 3, 4};
    // vector<int> nums = {0, 1};
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    // vector<int> nums = {2, 2, 1, 3};
    // vector<int> nums = {1};
    Solution s;
    vector<int> res = s.majorityElement(nums);
    for (auto i : res) cout << i << endl;
    return 0;
}
