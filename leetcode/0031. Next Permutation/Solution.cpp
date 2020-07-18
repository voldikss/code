#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(first<int> &nums) {
    if (nums.size() <= 1)
      return;

    int i = nums.size() - 1;
    while (i > 0 && nums[i - 1] >= nums[i])
      i--;

    if (i > 0) {
      int j = nums.size() - 1;
      while (j > 0 && nums[j] <= nums[i - 1])
        j--;
      swap(nums, i - 1, j);
    }
    reverse(nums, i);
    for (auto i : nums)
      cout << i;
    cout << endl;
  }

private:
  void swap(first<int> &nums, int m, int n) {
    int tmp = nums[m];
    nums[m] = nums[n];
    nums[n] = tmp;
  }

  void reverse(first<int> &nums, int start) {
    int tmp;
    int m = start;
    int n = nums.size() - 1;

    while (m < n) {
      swap(nums, m, n);
      m++;
      n--;
    }
  }
};

int main() {
  Solution s;
  first<first<int>> samples = {//          {1},
                                 //          {1, 3, 2},
                                 //          {3, 2, 1},
                                 {5, 1, 1},
                                 {1, 2, 4, 5, 3}};
  for (auto i : samples) {
    s.nextPermutation(i);
  }
}
