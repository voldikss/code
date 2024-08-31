#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return intervals;
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;
        for (auto i : intervals) q.push(i);
        while (q.size() >= 2) {
            vector<int> i1 = q.top();
            q.pop();
            vector<int> i2 = q.top();
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
    vector<vector<int>> input = {{1, 4}};
    Solution s;
    vector<vector<int>> res = s.merge(input);
    for (auto i : res) cout << "{" << i[0] << ", " << i[1] << "}, ";
    cout << endl;
    return 0;
}
