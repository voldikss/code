#include "../../include/global.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        vector<int> leftmax(n);
        leftmax[0] = heights[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], heights[i]);
        }
        vector<int> rightmax(n);
        rightmax[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], heights[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(leftmax[i], rightmax[i]) - heights[i];
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height{4, 2, 3};
    auto res = s.trap(height);
    cout << res << endl;
    return 0;
}
