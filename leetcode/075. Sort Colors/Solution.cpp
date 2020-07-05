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
        int redCount = 0;
        int whiteCount = 0;
        int blueCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                redCount++;
            else if (nums[i] == 1)
                whiteCount++;
            else
                blueCount++;
        }
        // cout << redCount << endl;
        // cout << whiteCount << endl;
        // cout << blueCount << endl;
        int i = 0;
        for (; i < redCount; i++)
            nums[i] = 0;
        for (; i < whiteCount + redCount; i++)
            nums[i] = 1;
        for (; i < nums.size(); i++)
            nums[i] = 2;
    }
};

int main() {
    Solution s;
    // vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> nums = {2, 0, 1};
    s.sortColors(nums);
    cout << nums << endl;
    return 0;
}
