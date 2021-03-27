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
        int min = nums[0];
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            if (nums[i] <= min) {
                min = nums[i];
            } else {
                for (int j = i + 1; j < len; j++) {
                    if (nums[j] > min && nums[j] < nums[i]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, char** argv) {

    return 0;
}
