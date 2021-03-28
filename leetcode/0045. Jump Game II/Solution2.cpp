#include "../../include/vector.hpp"
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
        // TODO
        int end = 0;
        int step = 0;
        int maxpos = 0;
        int i = 0;
        while (end < nums.size() - 1) {
            maxpos = max(maxpos, nums[i] + i);
            if (i == end) {
                step++;
                end = maxpos;
            }
            i++;
        }
        return step;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // auto nums = vector<int>{2, 3, 1, 1, 4};
    auto nums = vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};
    // auto nums = vector<int>{2, 3, 1, 1, 4};
    // auto nums = vector<int>{5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    // auto nums = vector<int>{2, 3, 0, 1, 4};
    auto res = s.jump(nums);
    cout << "res: " << res << endl;
    return 0;
}
