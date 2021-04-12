#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        int index1 = 0;
        int index2 = 0;
        int prev = 0;
        int curr = 0;
        for (int i = 0; i <= len / 2; i++) {
            prev = curr;
            if (index2 >= len2 ||
                (index1 < len1 && nums1[index1] < nums2[index2]))
                curr = nums1[index1++];
            else
                curr = nums2[index2++];
        }

        // for (auto i : tmp) {
        //     cout << i << endl;
        // }

        if (len % 2 == 1)
            return curr;
        else
            return (prev + curr) / 2.0;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
    return 0;
}
