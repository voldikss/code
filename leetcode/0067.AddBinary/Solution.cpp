#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        string res;
        int p1 = a.size() - 1;
        int p2 = b.size() - 1;

        int flag = 0;
        while (p1 >= 0 || p2 >= 0 || flag != 0) {
            if (p1 >= 0) flag += a[p1--] - '0';
            if (p2 >= 0) flag += b[p2--] - '0';
            res.push_back(flag % 2 + '0');
            flag /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    string a = "1010", b = "1011";
    auto res = s.addBinary(a, b);
    cout << res << endl;
    return 0;
}
