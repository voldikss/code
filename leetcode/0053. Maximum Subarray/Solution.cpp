#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
        int thissum = 0;
        int maxsum = INT32_MIN;
        for (auto n : nums) {
            thissum = thissum + n;
            if (thissum < 0) {
                maxsum = max(maxsum, thissum);
                thissum = 0;
            } else
                maxsum = max(maxsum, thissum);
        }
        return maxsum;
    }
};

int main() {
    vector<vector<int>> samples = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4}, {0}, {-2}, {-1, -2}};
    Solution s;
    for (auto i : samples)
        cout << s.maxSubArray(i) << endl;
}
