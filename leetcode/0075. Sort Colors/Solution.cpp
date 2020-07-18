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
        int redIndex = 0;
        int blueIndex = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            cout << nums << " " << i << endl;
            if (i > blueIndex) break;
            if (nums[i] == 0)
                nums[redIndex++] = 0;
            else if (nums[i] == 2) {
                // 1. handle end
                while (1) {
                    if (blueIndex < 0) return;
                    if (nums[blueIndex] == 0) {
                        if (blueIndex >= redIndex)
                            nums[redIndex++] = 0;
                        break;
                    } else if (nums[blueIndex] == 1) {
                        break;
                    } else {
                        blueIndex--;
                    }
                }
                // 2. add this
                if (i < blueIndex)
                    nums[blueIndex--] = 2;
            }
            if (i >= redIndex && i <= blueIndex) nums[i] = 1;
        }
    }
};

int main() {
    Solution s;
    // vector<int> nums = {2, 0, 2, 1, 1, 0};
    // vector<int> nums = {2};
    vector<int> nums = {0, 2};
    // vector<int> nums = {1, 2};
    // vector<int> nums = {2, 0, 1};
    // vector<int> nums = {2, 0, 2};
    // vector<int> nums = {2, 2};
    s.sortColors(nums);
    cout << nums << endl;
    return 0;
}
