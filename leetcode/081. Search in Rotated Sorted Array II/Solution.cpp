#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const list<T> &l) {
    for (auto &i : l) os << i << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto x : vec) os << x << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vec) {
    for (auto &x : vec) os << x << endl;
    return os;
}

class Solution {
  public:
    bool search(vector<int> &nums, int target) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return nums[0] == target;
        int left;
        int right;
        int i;
        for (i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (target >= nums[0]) {
                    left = 0;
                    right = i;
                } else {
                    left = i + 1;
                    right = nums.size() - 1;
                }
                break;
            }
        }
        if (i == nums.size() - 1) {
            if (nums[0] == nums[nums.size() - 1]) return nums[0] == target;
            left = 0;
            right = nums.size() - 1;
        }
        // cout << left << endl;
        // cout << right << endl;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                // cout << mid << endl;
                return true;
            } else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution s;
    // vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    // cout << s.search(nums, 0) << endl;
    // cout << s.search(nums, 2) << endl;
    // cout << s.search(nums, 3) << endl;

    // vector<int> nums = {0, 0, 0, 0};
    // cout << s.search(nums, 0) << endl;
    // cout << s.search(nums, 1) << endl;

    // vector<int> nums = {1, 0, 0, 0};
    // cout << s.search(nums, 0) << endl;
    // cout << s.search(nums, 1) << endl;

    // vector<int> nums = {1, 3};
    // cout << s.search(nums, 0) << endl;
    // cout << s.search(nums, 1) << endl;
    // cout << s.search(nums, 3) << endl;

    vector<int> nums = {3, 1};
    // cout << s.search(nums, 0) << endl;
    // cout << s.search(nums, 1) << endl;
    cout << s.search(nums, 3) << endl;
    return 0;
}
