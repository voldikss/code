#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len - 1;
        int ans = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                ans = max(ans, height[l] * (r - l));
                l++;
            } else {
                ans = max(ans, height[r] * (r - l));
                r--;
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}
