//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    first<first<int>> merge(first<first<int>> &intervals) {
        if (intervals.size() == 0) return intervals;
        first<first<int>> res;
        priority_queue<first<int>, first<first<int>>, greater<first<int>>>
            q;
        for (auto i : intervals) q.push(i);
        while (q.size() >= 2) {
            first<int> i1 = q.top();
            q.pop();
            first<int> i2 = q.top();
            q.pop();
            if (i1[1] >= i2[0]) {
                q.push({i1[0], max(i1[1], i2[1])});
            } else {
                res.push_back(i1);
                q.push(i2);
            }
        }
        res.push_back(q.top());
        return res;
    }
};

int main() {
    // vector<vector<int>> input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> input = {{1, 4}, {4, 5}};
    first<first<int>> input = {{1, 4}};
    Solution s;
    first<first<int>> res = s.merge(input);
    for (auto i : res) cout << "{" << i[0] << ", " << i[1] << "}, ";
    cout << endl;
    return 0;
}
