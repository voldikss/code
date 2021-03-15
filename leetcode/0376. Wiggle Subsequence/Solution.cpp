#include "../../include/vector.cpp"
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
        if (len == 0) return 0;
        if (len == 1) return 1;
        if (len == 2) {
            if (nums[0] == nums[1])
                return 1;
            else
                return 2;
        }
        int res;
        if (nums[0] == nums[1])
            res = 1;
        else
            res = 2;
        int p1 = 1;
        int p2 = 2;
        int prediff = nums[1] - nums[0];
        while (p2 < len) {
            if (nums[p2] != nums[p1]) {
                int curdiff = nums[p2] - nums[p1];
                if (prediff == 0 || (curdiff > 0) != (prediff > 0)) {
                    res++;
                }
                prediff = curdiff;
            }
            p1++;
            p2++;
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
