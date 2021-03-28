#include "../../include/vector.hpp"
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

bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[0] < b[0]) return true;
    if (a[0] > b[0]) return false;
    if (a[1] < b[1]) return true;
    return false;
}

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), comp);
        int len = intervals.size();
        vector<int> length(len, 1);
        length[0] = 1;
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (intervals[j][1] <= intervals[i][0]) {
                    length[i] = max(length[i], length[j] + 1);
                    break;
                }
            }
        }

        // cout << intervals << endl;
        return len - *max_element(length.begin(), length.end());
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
