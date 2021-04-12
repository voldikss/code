#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int res = 0;
        auto before = intervals.begin();
        for (auto it = before + 1; it != intervals.end(); it++) {
            if ((*it)[0] >= (*before)[1]) {
                before = it;
            } else {
                res++;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals{{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    auto res = s.eraseOverlapIntervals(intervals);
    cout << res << endl;
    return 0;
}
