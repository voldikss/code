#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        stack<int> deStack;
        for (int i = 0; i < n; ++i) {
            if (deStack.empty() || A[deStack.top()] > A[i]) {
                deStack.push(i);
            }
        }

        int maxWidth = 0;
        for (int i = n - 1; i > maxWidth; --i) {
            while (!deStack.empty() && A[i] >= A[deStack.top()]) {
                maxWidth = max(maxWidth, i - deStack.top());
                deStack.pop();
            }
        }
        return maxWidth;
    }
};

int main() {
    Solution s;
    vector<int> sample = {6, 0, 8, 2, 1, 5};
    // vector<int> sample = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    int res = s.maxWidthRamp(sample);
    cout << res << endl;
}
