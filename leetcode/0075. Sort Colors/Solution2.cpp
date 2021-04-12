#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;
        while (i <= r) {
            if (nums[i] < 1) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            } else if (nums[i] > 1) {
                swap(nums[i], nums[r]);
                r--;
            } else {
                i++;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    // vector<int> nums = {2};
    // vector<int> nums = {0, 2};
    // vector<int> nums = {1, 2};
    // vector<int> nums = {2, 0, 1};
    // vector<int> nums = {2, 0, 2};
    // vector<int> nums = {2, 2};
    s.sortColors(nums);
    cout << nums << endl;
    return 0;
}
