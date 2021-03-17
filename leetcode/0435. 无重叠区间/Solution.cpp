#include "../../include/vector.cpp"
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
        sort(intervals.begin(), intervals.end(), comp);
        cout << intervals << endl;
        int res = 0;
        int p1 = 0;
        int p2 = 1;
        while (p2 < intervals.size()) {
            if (intervals[p1][0] < intervals[p2][0]) {
                // intervals[p1][0] < intervals[p2][0]
                if (intervals[p1][1] > intervals[p2][0]) {
                    // must remove
                    res++;
                    if (intervals[p1][1] >= intervals[p2][1]) {
                        // remove intervals[p1]
                        p1 = p2;
                        p2++;
                    } else {
                        // remove intervals[p2]
                        p2++;
                    }
                } else {
                    // move forward
                    p1 = p2;
                    p2++;
                }
            } else if (intervals[p1][1] < intervals[p2][1]) {
                // intervals[p1][0] == intervals[p2][0] but intervals[p1][1] < intervals[p2][1]
                // remove intervals[p2]
                p2++;
                res++;
            } else {
                // intervals[p1][0] == intervals[p2][0] and intervals[p1][1] == intervals[p2][1]
                // remove intervals[p2]
                p2++;
                res++;
            }
        }

        // cout << intervals << endl;
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
