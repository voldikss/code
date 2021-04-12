#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    int pos1, pos2;
    int m_target;
    vector<int> m_nums;

  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        pos1 = nums.size();
        pos2 = -1;
        m_target = target;
        m_nums = nums;
        binarySearch(0, nums.size() - 1);
        if (pos1 == nums.size()) pos1 = -1;
        return {pos1, pos2};
    }

    void binarySearch(int low, int high) {
        if (low > high) return;
        int mid = low + (high - low) / 2;
        if (m_nums[mid] < m_target) {
            binarySearch(mid + 1, high);
        } else if (m_nums[mid] > m_target) {
            binarySearch(low, mid - 1);
        } else {
            if (mid < pos1) pos1 = mid;
            if (mid > pos2) pos2 = mid;
            binarySearch(low, mid - 1);
            binarySearch(mid + 1, high);
        }
    }
};

int main() {
    // vector<int> nums = {1};
    // int target = 1;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution s;
    auto res = s.searchRange(nums, target);
    cout << res << endl;
    return 0;
}
