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
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int major;
        int count = 0;
        for (int n : nums) {
            if (count == 0) {
                major = n;
                count++;
            } else if (n == major) {
                count++;
            } else {
                count--;
            }
        }
        return major;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    vector<int> nums = {0};
    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int res = s.majorityElement(nums);
    cout << res << endl;
    return 0;
}
