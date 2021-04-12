#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

/* 用 vector 更直观一点可惜超时
 * class Solution {
 *   public:
 *     int maxValue(int n, int index, int maxSum) {
 *         int left = index;
 *         int right = index;
 *         vector<int> arr(n, 1);
 *         maxSum -= n;
 *         while (left > 0 || right < n - 1) {
 *             int width = right - left + 1;
 *             if (maxSum >= width) {
 *                 for (int i = left; i <= right; i++) arr[i]++;
 *                 maxSum -= width;
 *                 left = max(0, left - 1);
 *                 right = min(n - 1, right + 1);
 *             } else
 *                 break;
 *         }
 *         return *max_element(arr.begin(), arr.end()) + maxSum / n;
 *     }
 * };
 */

class Solution {
  public:
    int maxValue(int n, int index, int maxSum) {
        int left = index;
        int right = index;
        int ans = 1;
        maxSum -= n;
        while (left > 0 || right < n - 1) {
            int width = right - left + 1;
            if (maxSum >= width) {
                ans++;
                maxSum -= width;
                left = max(0, left - 1);
                right = min(n - 1, right + 1);
            } else
                break;
        }
        return ans + maxSum / n;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // int n = 4, index = 2, maxSum = 6;
    // int n = 6, index = 1, maxSum = 10;
    int n = 3, index = 2, maxSum = 18;
    auto res = s.maxValue(n, index, maxSum);
    cout << res << endl;
    return 0;
}
