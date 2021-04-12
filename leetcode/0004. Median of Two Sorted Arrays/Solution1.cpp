#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int index1 = 0;
        int index2 = 0;
        int index = 0;
        vector<int> tmp;
        while (index++ < (len1 + len2))
            if (index1 >= len1)
                while (index2 < len2) tmp.push_back(nums2[index2++]);
            else if (index2 >= len2)
                while (index1 < len1) tmp.push_back(nums1[index1++]);
            else if (nums1[index1] < nums2[index2])
                tmp.push_back(nums1[index1++]);
            else
                tmp.push_back(nums2[index2++]);

        // for (auto i : tmp) {
        //     cout << i << endl;
        // }

        if (tmp.size() % 2 == 1)
            return tmp[tmp.size() / 2];
        else
            return (tmp[tmp.size() / 2 - 1] + tmp[tmp.size() / 2]) / 2.0;
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
