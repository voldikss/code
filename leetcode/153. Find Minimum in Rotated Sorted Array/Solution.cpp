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
  int findMin(vector<int> &nums) {
    if (nums.size() == 0) {
      return nums[-1];
    }
    if (nums.size() == 1) {
      return nums[0];
    }

    if (nums[0] < nums[nums.size() - 1]) {
      return nums[0];
    }

    int begin, end, mid, rotate_pos;
    begin = 0;
    end = nums.size() - 1;
    mid = (begin + end) / 2;
    // find the rotate position first
    while (begin <= end) {
      if (nums[mid] >= nums[begin] && nums[mid + 1] > nums[begin]) {
        begin = mid;
        mid = (begin + end) / 2;
      } else if (nums[mid] < nums[begin] && nums[mid + 1] < nums[begin]) {
        end = mid;
        mid = (begin + end) / 2;
      } else if (nums[mid] >= nums[begin] && nums[mid + 1] < nums[begin]) {
        rotate_pos = mid + 1;
        break;
      }
    }
    return nums[rotate_pos];
  }
};

int main() {
  Solution s;
  // vector<int> sample({4, 5, 6, 7, 0, 1, 2});
  // vector<int> sample({4, 5, 0, 1, 2});
  // vector<int> sample({1, 2});
  // vector<int> sample({1, 3});
  // vector<int> sample({3, 1});
  vector<int> sample({4,5,6,7,0,1,2});
  // vector<int> sample({3, 4, 5, 1, 2});
  int ans = s.findMin(sample);
  cout << ans << endl;

  // cout << s.binarySearch(sample, 0, 1, 1) << endl;
}
