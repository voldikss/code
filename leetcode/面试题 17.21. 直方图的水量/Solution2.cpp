#include "../../include/global.hpp"
#include <algorithm>
#include <cassert>
#include <numeric>
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

class Solution {
public:
    int trap(vector<int>& heights) {
        int len = heights.size();
        int left = 0;
        int right = len - 1;
        int total = 0;
        int height = 1;
        while (left <= right) {
            while (left <= right && heights[left] < height) left++;
            while (left <= right && heights[right] < height) right--;
            total += (right - left + 1);
            height++;
        }
        return total - accumulate(heights.begin(), heights.end(), 0);
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
