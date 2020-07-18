#include <algorithm>
#include <cassert>
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
  private:
    int pos1, pos2;
    int m_target;
    vector<int> m_nums;

  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        pos1 = nums.size();
        pos2 = -1;
        m_target = target;
        m_nums = nums;
        binarySearch(0, nums.size() - 1);
        if (pos1 == nums.size()) pos1 = -1;
        return {pos1, pos2};
    }

    void binarySearch(int low, int high) {
        if (low > high) return;
        int mid = low + (high - low) / 2;
        if (m_nums[mid] < m_target) {
            binarySearch(mid + 1, high);
        } else if (m_nums[mid] > m_target) {
            binarySearch(low, mid - 1);
        } else {
            if (mid < pos1) pos1 = mid;
            if (mid > pos2) pos2 = mid;
            binarySearch(low, mid - 1);
            binarySearch(mid + 1, high);
        }
    }
};

int main() {
    // vector<int> nums = {1};
    // int target = 1;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution s;
    auto res = s.searchRange(nums, target);
    cout << res << endl;
    return 0;
}
