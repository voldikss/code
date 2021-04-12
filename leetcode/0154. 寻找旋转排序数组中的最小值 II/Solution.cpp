#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums[0];
        int left = 0;
        int right = n - 1;

        while (nums[left] == nums[right]) {
            if (left == n - 1) break;
            left++;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return min(nums[left], nums[right]);
    }
};

int main(int argc, char** argv) {

    return 0;
}
