#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p3 = nums1.size() - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p3] = nums1[p1];
                p1--;
            } else {
                nums1[p3] = nums2[p2];
                p2--;
            }
            p3--;
        }
        if (p2 >= 0) {
            while (p2 >= 0) nums1[p3--] = nums2[p2--];
        }
    }
};

int main() {
    Solution s;
    // vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    // int m = 3;
    // vector<int> nums2 = {2, 5, 6};
    // int n = 3;
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = 1;
    s.merge(nums1, m, nums2, n);
    cout << nums1 << endl;
    return 0;
}
