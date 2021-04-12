#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i <= nums.size() - 4; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j <= nums.size() - 3; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int lp = j + 1;
                int rp = nums.size() - 1;
                if (nums[i] + nums[j] + nums[lp] + nums[lp + 1] > target)
                    continue;
                if (nums[i] + nums[j] + nums[rp] + nums[rp - 1] < target)
                    continue;
                while (lp < rp) {
                    int sum = nums[i] + nums[j] + nums[lp] + nums[rp];
                    if (sum < target)
                        lp++;
                    else if (sum > target)
                        rp--;
                    else {
                        res.push_back({nums[i], nums[j], nums[lp], nums[rp]});
                        while (lp < rp && nums[lp] == nums[lp + 1]) lp++;
                        while (lp < rp && nums[rp] == nums[rp - 1]) rp--;
                        lp++;
                        rp--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    s.fourSum(nums, target);
    return 0;
}
