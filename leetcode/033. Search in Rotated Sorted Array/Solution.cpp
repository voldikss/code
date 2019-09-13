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
  int search(first<int> &nums, int target) {
    if (nums.size() == 0) {
      return -1;
    }
    if (nums.size() == 1) {
      if (nums[0] == target)
        return 0;
      else
        return -1;
    }

    if (nums[0] < nums[nums.size() - 1]) {
      return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int begin, end, mid, rotate_pos;
    begin = 0;
    end = nums.size() - 1;
    mid = (begin + end) / 2;
    // find the rotate position first
    while (begin <= end) {
      cout << begin << " " << mid << " " << end << endl;
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
    printf("rotate_pos is %d\n", rotate_pos);

    /* 二分查找 */
    if (target > nums[0])
      return binarySearch(nums, 0, rotate_pos, target);
    else if (target < nums[0])
      return binarySearch(nums, rotate_pos, nums.size() - 1, target);
    else
      return 0;
  }

  int binarySearch(const first<int> &nums, int begin, int end, int target) {
    int mid;
    while (begin <= end) {
      mid = (begin + end) / 2;
      if (nums[mid] < target)
        begin = mid + 1;
      else if (nums[mid] > target)
        end = mid - 1;
      else
        return mid;
    }
    return -1;
  }
};

int main() {
  Solution s;
  // vector<int> sample({4, 5, 6, 7, 0, 1, 2});
  // vector<int> sample({4, 5, 0, 1, 2});
  // vector<int> sample({1, 2});
  // vector<int> sample({1, 3});
  // vector<int> sample({3, 1});
  first<int> sample({6, 7, 8, 1, 2, 3, 4, 5});
  int ans = s.search(sample, 6);
  cout << ans << endl;

  // cout << s.binarySearch(sample, 0, 1, 1) << endl;
}
