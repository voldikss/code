#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0], tmp;
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            tmp = nums[i];
            maxp = max(tmp, maxp);
            for (int j = i; j < N; ++j) {
                if (j != i)
                    tmp = tmp * nums[j];
                maxp = max(tmp, maxp);
            }
        }
        return maxp;
    }
};

int main() {
    Solution s;
    vector<vector<int>> samples = {{2, 3, -2, 4}, {-2, 0, -1}, {3}, {-3}, {0}, {-3, 0}, {0, 2}};
    for (auto& i : samples) {
        cout << s.maxProduct(i) << endl;
    }
}
