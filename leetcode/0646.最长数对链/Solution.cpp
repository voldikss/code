#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[0] < b[0]) return true;
    if (a[0] > b[0]) return false;
    if (a[1] < b[1]) return true;
    return false;
}

class Solution {
  public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0) return 0;
        if (pairs[0].size() == 0) return 1;
        int len = pairs.size();
        sort(pairs.begin(), pairs.end(), comp);
        vector<int> dp(len, 1);
        dp[0] = 1;
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (pairs[j][1] < pairs[i][0]) {
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
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    auto res = s.findLongestChain(pairs);
    cout << res << endl;
    return 0;
}
