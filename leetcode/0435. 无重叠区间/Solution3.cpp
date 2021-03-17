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
        // TODO greedy algorithm: better code style
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
