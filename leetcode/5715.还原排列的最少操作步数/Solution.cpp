#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int reinitializePermutation(int n) {
        vector<int> perm;
        perm.reserve(n);
        for (int i = 0; i < n; i++) perm.push_back(i);
        int ans = 1;
        vector<int> arr(perm);
        while (true) {
            vector<int> tmp(arr);
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    arr[i] = tmp[i / 2];
                } else {
                    arr[i] = tmp[n / 2 + (i - 1) / 2];
                }
            }
            if (arr == perm) break;
            ans++;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    auto ans = s.reinitializePermutation(4);
    cout << ans << endl;
    return 0;
}
