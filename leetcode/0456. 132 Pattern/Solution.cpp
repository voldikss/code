//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool find132pattern(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return false;
        int first = INT32_MAX;
        for (int i = 0; i < n; ++i) {
            first = min(first, nums[i]);
            if (first == nums[i]) continue;
            for (int j = n - 1; j > i; --j) {
                if (first < nums[j] && nums[i] > nums[j]) return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> input = {3, 1, 4, 2};
    Solution s;
    bool res = s.find132pattern(input);
    cout << res << endl;
    return 0;
}
