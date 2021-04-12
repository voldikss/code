#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
  public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        long long ans = 0;

        int start = 0;
        int end = len - 1;
        while (start < end) {
            if (nums[start] + nums[end] <= target) {
                ans += (end - start);
                start++;
            } else
                end--;
        }

        return ans % MOD;
    }
};

int main(int argc, char** argv) {

    return 0;
}
