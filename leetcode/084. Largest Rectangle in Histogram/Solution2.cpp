//============================================================================
// FileName: Solution2.cpp
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

// 这个也该好好学一下
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        return calcArea(heights, 0, heights.size() - 1);
    }

    int calcArea(vector<int> heights, int start, int end) {
        if (start > end) return 0;
        int minIndex = start;
        for (int i = start; i <= end; ++i)
            if (heights[i] < heights[minIndex]) minIndex = i;
        return max({heights[minIndex] * (end - start + 1),
                    max(calcArea(heights, start, minIndex - 1),
                        calcArea(heights, minIndex + 1, end))});
    }
};

int main() {
    Solution s;
    vector<int> sample{2, 1, 5, 6, 2, 3};
    // vector<int> sample{1,1};
    // vector<int> sample{2, 1, 2};
    int res = s.largestRectangleArea(sample);
    cout << "res: " << res << endl;
}
