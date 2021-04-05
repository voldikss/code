#include "../../include/global.hpp"
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

class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        int prediff = nums[1] - nums[0];
        int res = prediff == 0 ? 1 : 2;
        for (int i = 2; i < len; i++) {
            int curdiff = nums[i] - nums[i - 1];
            if (curdiff != 0) {
                if (prediff == 0 || ((prediff > 0) != (curdiff > 0))) {
                    res++;
                }
                prediff = curdiff;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    auto nums = vector<int>{1, 7, 4, 9, 2, 5};
    // auto nums = vector<int>{1,17,5,10,13,15,10,5,16,8};
    // auto nums = vector<int>{1,2,3,4,5,6,7,8,9};
    auto res = s.wiggleMaxLength(nums);
    cout << res << endl;
    return 0;
}
