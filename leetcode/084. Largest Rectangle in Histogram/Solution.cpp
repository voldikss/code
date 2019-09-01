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
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        int res = 0;
        int n = heights.size();
        stack<int> incStack;
        for (int i = 0; i < n; ++i) {
            // cout << "i=" << i << endl;
            while (!incStack.empty() && heights[incStack.top()] >= heights[i]) {
                int h = heights[incStack.top()];
                // cout << "h=" << h << endl;
                // cout << "width=" << i - incStack.top() << endl;
                incStack.pop();
                // 万一栈顶前面的一部分没有了
                // 那这部分肯定是因为比当前栈顶的高度高所以在之前消去了
                // 因此应该把这段宽度也算上
                int sidx = incStack.empty() ? -1 : incStack.top();
                res = max(res, h * (i - sidx - 1));
            }
            incStack.push(i);
        }
        return res;
    }
};

int main() {
    Solution s;
    // vector<int> sample{2, 1, 5, 6, 2, 3};
    // vector<int> sample{1,1};
    vector<int> sample{2, 1, 2};
    int res = s.largestRectangleArea(sample);
    cout << "res: " << res << endl;
}
