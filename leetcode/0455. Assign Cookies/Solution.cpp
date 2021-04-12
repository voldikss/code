#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        size_t gindex = 0;
        size_t sindex = 0;

        while (gindex < g.size() && sindex < s.size()) {
            if (g[gindex] <= s[sindex]) {
                gindex++;
            }
            sindex++;
        }
        return gindex;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    auto g = vector<int>{7, 8, 9, 10}, s = vector<int>{5, 6, 7, 8};
    auto res = sol.findContentChildren(g, s);
    cout << res << endl;
    return 0;
}
