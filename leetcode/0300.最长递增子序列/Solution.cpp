#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> length(len, 1);
        length[len - 1] = 1;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (nums[i] < nums[j]) {
                    length[i] = max(length[j] + 1, length[i]);
                }
            }
        }
        cout << length << endl;
        return *max_element(length.begin(), length.end());
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums{0, 1, 0, 3, 2, 3};
    auto res = s.lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}
