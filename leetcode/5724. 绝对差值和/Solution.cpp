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

const int MOD = 1e9 + 7;

class Solution {
  public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int maxdiffpos = 0;
        int maxdiff = 0;
        int len = nums1.size();
        for (int i = 0; i < len; i++) {
            unsigned diff = abs(nums1[i] - nums2[i]);
            if (diff > maxdiff) {
                maxdiff = diff;
                maxdiffpos = i;
            }
        }

        int mindiffpos = 0;
        int mindiff = maxdiff;
        for (int i = 0; i < len; i++) {
            unsigned diff = abs(nums1[i] - nums2[maxdiffpos]);
            if (diff < mindiff) {
                mindiff = diff;
                mindiffpos = i;
            }
        }

        nums1[maxdiffpos] = nums1[mindiffpos];
        int ans = 0;
        for (int i = 0; i < len; i++) {
            unsigned diff = abs(nums1[i] - nums2[i]);
            ans += diff;
            ans %= MOD;
        }

        return ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}
