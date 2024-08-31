#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string addStrings(string num1, string num2) {
        string res;
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;

        int flag = 0;
        while (p1 >= 0 || p2 >= 0 || flag != 0) {
            if (p1 >= 0) flag += num1[p1--] - '0';
            if (p2 >= 0) flag += num2[p2--] - '0';
            res.push_back(flag % 10 + '0');
            flag /= 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    auto res = s.addStrings("123", "6789");
    // auto res = s.addStrings("1", "9");
    cout << res << endl;
    return 0;
}
