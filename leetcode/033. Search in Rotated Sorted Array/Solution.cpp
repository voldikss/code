//////////////////////////////////////////////////////////////////////////////
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left, right, mid, rotate_pos;
    left = 0;
    right = nums.size();
    mid = (left + right) / 2;
    // find the rotate position first
    while (left <= right) {
      if (nums[mid] >= nums[left] && nums[mid + 1] > nums[left]) {
        right = mid;
        mid = (left + right) / 2;
      } else if (nums[mid] < nums[left] && nums[mid + 1] < nums[left]) {
        left = mid;
        mid = (left + right) / 2;
      } else if (nums[mid] > nums[left] && nums[mid + 1] < nums[left]) {
        rotate_pos = mid;
        break;
      }
    }
    printf("%d\n", rotate_pos);
    // 二叉查找
    // TODO

    return 0;
  }
};

int main() {
  Solution s;
  vector<int> sample({4, 5, 6, 7, 0, 1, 2});
  s.search(sample, 0);
}
