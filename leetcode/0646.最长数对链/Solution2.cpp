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
        // TODO: greedy algorithm
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    auto res = s.findLongestChain(pairs);
    cout << res << endl;
    return 0;
}
