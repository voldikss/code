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
#include <variant>
#include <vector>
using namespace std;

// 参考别人的解法，倒序太绝了
class Solution {
  public:
    bool canJump(vector<int>& nums) {
        int lastpos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] + i >= lastpos) {
                lastpos = i;
            }
        }
        return lastpos == 0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // auto nums = vector<int>{3, 2, 1, 0, 4};
    auto nums = vector<int>{0, 2, 3};
    // auto nums = vector<int>{2, 3, 1, 1, 4};
    auto res = s.canJump(nums);
    cout << res << endl;
    return 0;
}
