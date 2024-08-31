#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int len = intervals.size();
        int p2 = 1;
        vector<int> prev = intervals[0];
        while (p2 < len) {
            auto curr = intervals[p2];
            //     cout << curr[0] << ' ' << curr[1] << endl;
            if (prev[1] >= curr[0]) {
                if (prev[1] <= curr[1]) prev[1] = curr[1];
            } else {
                res.push_back(prev);
                prev = curr;
            }
            p2++;
        }
        res.push_back(prev);
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto res = s.merge(intervals);
    cout << res << endl;
    return 0;
}
