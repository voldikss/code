#include "../../include/global.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
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

class Solution {
  public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        auto vec2 = vector<int>(len);
        nums[len - 1] = 0;
        for (int i = len - 2; i >= 0; i--) {
            int min_steps = INT_MAX / 2; // ...
            if (nums[i] == 0) {
                vec2[i] = min_steps;
                continue;
            }
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j > len - 1) break;
                if (vec2[i + j] < min_steps) min_steps = vec2[i + j];
            }
            vec2[i] = 1 + min_steps;
        }
        cout << vec2 << endl;
        return vec2[0];
    }
};

int main(int argc, char** argv) {
    Solution s;
    // auto nums = vector<int>{2, 3, 1, 1, 4};
    // auto nums = vector<int>{2, 3, 1, 1, 4};
    auto nums = vector<int>{5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    // auto nums = vector<int>{2, 3, 0, 1, 4};
    auto res = s.jump(nums);
    cout << "res: " << res << endl;
    return 0;
}
