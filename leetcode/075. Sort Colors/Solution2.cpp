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
    void sortColors(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;
        while (i <= r) {
            if (nums[i] < 1) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            } else if (nums[i] > 1) {
                swap(nums[i], nums[r]);
                r--;
            } else {
                i++;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    // vector<int> nums = {2};
    // vector<int> nums = {0, 2};
    // vector<int> nums = {1, 2};
    // vector<int> nums = {2, 0, 1};
    // vector<int> nums = {2, 0, 2};
    // vector<int> nums = {2, 2};
    s.sortColors(nums);
    cout << nums << endl;
    return 0;
}
