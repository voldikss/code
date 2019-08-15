#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// https://leetcode-cn.com/problems/maximum-product-subarray/solution/duo-chong-si-lu-qiu-jie-by-powcai-3/
// 利用正反序列，厉害
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    vector<int> nums_reverse(nums);
    reverse(nums_reverse.begin(), nums_reverse.end());

    for (int i = 1; i < nums.size(); ++i) {
      nums[i] *= nums[i - 1] == 0 ? 1 : nums[i - 1];
      nums_reverse[i] *= nums_reverse[i - 1] == 0 ? 1 : nums_reverse[i - 1];
    }

    return max(*max_element(nums.begin(), nums.end()),
               *max_element(nums_reverse.begin(), nums_reverse.end()));
  }
};

int main() {
  Solution s;
  vector<vector<int>> samples = {
      {2, 3, -2, 4}, {-2, 0, -1}, {3}, {-3}, {0}, {-3, 0}, {0, 2}, {-2, 0, -1}};
  for (auto &i : samples) {
    cout << s.maxProduct(i) << endl;
  }
}
