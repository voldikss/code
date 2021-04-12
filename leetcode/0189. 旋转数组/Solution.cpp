#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int i = 0;
        while (i < n / 2) {
            swap(nums[i], nums[n - 1 - i]);
            i++;
        }
        i = 0;
        while (i < k / 2) {
            swap(nums[i], nums[k - 1 - i]);
            i++;
        }
        i = k;
        while (i < (n + k) / 2) {
            swap(nums[i], nums[n + k - 1 - i]);
            i++;
        }
    }
};

int main(int argc, char** argv) {
    return 0;
}
