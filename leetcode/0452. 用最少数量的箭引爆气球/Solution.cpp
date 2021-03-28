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

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
        int len = points.size();
        vector<int> dp(len, 1);
        dp[0] = 1;
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (points[j][1] < points[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    break;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    auto res = s.findMinArrowShots(points);
    cout << res << endl;
    return 0;
}
