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

// 2021-03-30 每日一题，重做了一下
class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m - 1;
        while (lo < hi) {
            int mididx = lo + (hi - lo) / 2;
            int midval = matrix[mididx][0];
            if (midval < target)
                lo++;
            else if (midval > target)
                hi--;
            else
                return true;
        }
        if (matrix[lo][0] > target) lo = max(0, lo - 1);
        cout << lo << " " << hi << endl;
        // if (matrix[lo][n-1] < target) return false;
        // else if (matrix[lo][n-1] == target) return true;
        const auto& row = matrix[lo];
        lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mididx = lo + (hi - lo) / 2;
            int midval = row[mididx];
            if (midval < target)
                lo++;
            else if (midval > target)
                hi--;
            else
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    // vector<vector<int>> matrix = {{1, 3, 5, 7},
    //                               {10, 11, 16, 20},
    //                               {23, 30, 34, 50}};
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    cout << s.searchMatrix(matrix, 13) << endl;
    return 0;
}
