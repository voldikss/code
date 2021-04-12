#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

// 想了一天，代码写出来连我自己都不认识了，也不知道该如何表述解题思想大概思路就
// 是：先逆向遍历一遍，记录下 每个坐标 右边 最近的 比当前值大的 值 所在的坐标和
// 值然后正向遍历，从当前值开始填，时间复杂度 O(n)
class Solution {
  public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<pair<int, int>> rightmax(len);   // 右边比当前值大的最邻近的坐标。first: rightmax index; second：它本身应该被当做的值
        stack<pair<int, int>> monostk;          // 单调栈，用来生成rightmax。first: index; second: value
        for (int i = len - 1; i >= 0; i--) {
            pair<int, int> top = make_pair(i, height[i]);
            while (!monostk.empty() && monostk.top().second < height[i]) {
                top = monostk.top();
                monostk.pop();
            }
            if (monostk.empty()) {
                monostk.push(make_pair(i, height[i]));
                rightmax[i].first = top.first;
                rightmax[i].second = top.second;
            } else {
                rightmax[i].first = monostk.top().first;
                rightmax[i].second = height[i];
                monostk.push(make_pair(i, height[i]));
            }
        }

        int index = 0;
        int ans = 0;
        while (index < len) {
            int cur = rightmax[index].second;
            int end = rightmax[index].first;
            for (int i = index + 1; i < end; i++) {
                ans += (cur - rightmax[i].second);
            }
            if (index == end) {
                index = end + 1;
            } else {
                index = end;
            }
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
