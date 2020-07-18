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

template <typename T>
ostream &operator<<(ostream &os, const list<T> &l) {
    for (auto &i : l) os << i << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto x : vec) os << x << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vec) {
    for (auto &x : vec) os << x << endl;
    return os;
}

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int p = m + n;
        p--;
        m--;
        n--;
        while (p >= 0 && m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) {
                nums1[p] = nums1[m];
                p--;
                m--;
            } else {
                nums1[p] = nums2[n];
                p--;
                n--;
            }
        }
        if (n >= 0)
            for (int i = 0; i <= n; i++) nums1[i] = nums2[i];
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
