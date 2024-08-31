#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int mySqrt(int x) {
        double curr = 10;
        while (true) {
            double prev = curr;
            curr = 1 / 2.0 * (prev + x / prev);
            if ((int)prev == (int)curr) break;
        }
        return curr;
    }
};

int main() {
    Solution s;
    // cout << s.mySqrt(0) << endl;
    cout << s.mySqrt(2147395599) << endl;
    // cout << s.mySqrt(16) << endl;
    return 0;
}
