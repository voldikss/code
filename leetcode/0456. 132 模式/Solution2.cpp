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

class Solution {
  public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int len = nums.size();
        vector<int> minOfLeft(len, INT_MAX);
        for (int i = 1; i < len; i++) {
            minOfLeft[i] = min(minOfLeft[i - 1], nums[i - 1]);
        }

        stack<int> st;
        for (int i = len - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums[i]) {
                if (st.top() > minOfLeft[i] && st.top() < nums[i]) return true;
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    auto ans = s.find132pattern(nums);
    cout << ans << endl;
    return 0;
}
