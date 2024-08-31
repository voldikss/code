#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{{}};
        vector<vector<int>> cur;
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                for (auto& x : cur) {
                    x.push_back(nums[i]);
                    res.push_back(x);
                }
            } else {
                cur = {};
                auto tmp = res;
                for (auto x : tmp) {
                    x.push_back(nums[i]);
                    res.push_back(x);
                    cur.push_back(x);
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1, 2, 2};
    auto res = s.subsetsWithDup(nums);
    cout << res << endl;
    return 0;
}
