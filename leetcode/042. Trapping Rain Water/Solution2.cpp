//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

// 动态规划，暴力法的优化
class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n==0) return 0;
        int res = 0;

        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        for (int i = 0; i < n; ++i) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};

int main() {
    // vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> input = {};
    // vector<int> input = {9,0,0,0,9};
    // vector<int> input = {1,1,1,1,1};
    Solution s;
    int res = s.trap(input);
    cout << res << endl;
}
