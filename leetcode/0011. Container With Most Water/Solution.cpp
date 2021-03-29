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
    int maxArea(vector<int>& height) {
        int len = height.size();
        int maxcap = 0;
        int maxleft = height[0];
        for (int i = 0; i < len; i++) {
            if (height[i] < maxleft) {
                continue;
            } else {
                maxleft = height[i];
            }
            for (int j = len - 1; j > i; j--) {
                int cur = (j - i) * min(height[i], height[j]);
                maxcap = max(maxcap, cur);
            }
        }
        return maxcap;
    }
};

int main(int argc, char** argv) {

    return 0;
}
