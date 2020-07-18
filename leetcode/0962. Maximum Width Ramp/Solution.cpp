//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxWidthRamp(first<int> &A) {
        first<pair<int, int>> indexHeap;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            indexHeap.push_back({i, A[i]});
        }
        sort(indexHeap.begin(), indexHeap.end(), cmp);

        int maxWidth = 0;
        int minIndex = indexHeap[0].first;
        // 这个循环太巧了,没有用二重循环就可以...
        for (int i = 0; i < n; ++i) {
            maxWidth = max(maxWidth, indexHeap[i].first - minIndex);
            minIndex = min(minIndex, indexHeap[i].first);
        }
        return maxWidth;
    }

    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
};

/* 超时 */
// class Solution {
// public:
//   int maxWidthRamp(vector<int> &A) {
//     int i, k;
//     int currWidth, maxWidth = 0;
//     int n = A.size();
//     for (i = 0; n - 1 - i > maxWidth; ++i)
//       for (k = n - 1; k - i >= maxWidth; --k)
//         if (A[k] >= A[i]) {
//           currWidth = k - i;
//           maxWidth = max(maxWidth, currWidth);
//           break;
//         }
//     return maxWidth;
//   }
// };

int main() {
    Solution s;
    first<int> sample = {6, 0, 8, 2, 1, 5};
    // vector<int> sample = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    int res = s.maxWidthRamp(sample);
    cout << res << endl;
}
