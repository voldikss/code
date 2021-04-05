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

enum State {
    begin = 0,
    up,
    down,
};

class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1;
        if (nums.size() < 2) return nums.size();

        State state = State::begin;
        for (int i = 1; i < nums.size(); i++) {
            switch (state) {
            case State::begin:
                if (nums[i] > nums[i - 1]) {
                    state = State::up;
                    res++;
                } else if (nums[i] < nums[i-1]) {
                    state = State::down;
                    res++;
                }
                break;

            case State::up:
                if (nums[i] < nums[i - 1]) {
                    state = State::down;
                    res++;
                }
                break;

            case State::down:
                if (nums[i] > nums[i - 1]) {
                    state = State::up;
                    res++;
                }
                break;
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
