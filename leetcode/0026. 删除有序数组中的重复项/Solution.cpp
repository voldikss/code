#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        int fast = 1;
        int slow = 0;
        for (; fast < len; fast++) {
            if (nums[slow] != nums[fast]) {
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};

int main(int argc, char** argv) {

    return 0;
}
