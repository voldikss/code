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
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) return nums.size();
        int p = 1;
        int q = 2;
        while (q < nums.size()) {
            if (nums[q] == nums[p - 1])
                q++;
            else
                nums[++p] = nums[q++];
        }
        cout << nums << endl;
        return p + 1;
    }
};

int main() {
    Solution s;
    // vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> nums = {1, 2, 3};
    // vector<int> nums = {};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
