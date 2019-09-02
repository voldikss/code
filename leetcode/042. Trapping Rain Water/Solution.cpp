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

// 暴力法，这个我都没想到。。。
// 不过这个肯定过不了
class Solution {
  public:
    int trap(vector<int> &height) {
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            int max_left = 0;
            int max_right = 0;
            for (int m = i; m >= 0; --m) {
                max_left = max(max_left, height[m]);
            }
            for (int n = i; n < height.size(); ++n) {
                max_right = max(max_right, height[n]);
            }
            res += min(max_left, max_right) - height[i];
        }
        return res;
    }
};

int main() {
    vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> input = {0,2,0};
    // vector<int> input = {9,0,0,0,9};
    // vector<int> input = {1,1,1,1,1};
    Solution s;
    int res = s.trap(input);
    cout << res << endl;
}
