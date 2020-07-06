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
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        // res.push_back({});
        this->dfs(res, nums, {}, 0);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> path, int start) {
        res.push_back(path);
        if (start >= nums.size()) return;

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(res, nums, path, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    cout << "-------------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto res = s.subsets(nums);
    cout << res << endl;
    return 0;
}
