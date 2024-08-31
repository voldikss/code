#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) {
        vector<int> nums(num1.size() + num2.size(), 0);
        int p1, p2, p;
        int n1, n2, n;
        int carry_multi, carry_plus;
        for (p2 = num2.size() - 1; p2 >= 0; p2--) {
            n2 = num2[p2] - '0';
            carry_multi = 0;
            carry_plus = 0;
            for (p1 = num1.size() - 1; p1 >= 0; p1--) {
                n1 = num1[p1] - '0';
                n = n1 * n2 + carry_multi;
                carry_multi = n / 10;
                // cout << n1 << " " << n2 << " " << n << endl;
                p = p1 + p2 + 1;
                nums[p] += (n % 10 + carry_plus);
                carry_plus = nums[p] / 10;
                nums[p] %= 10;
                // cout << nums << endl;
            }
            if (carry_multi) nums[p - 1] = carry_multi;
            if (carry_plus) nums[p - 1] += 1;
        }

        string res;
        bool found = false;
        for (auto x : nums) {
            if (x == 0 && !found) continue;
            found = true;
            res.push_back(x + '0');
        }
        if (res.size() == 0) res.push_back('0');
        return res;
    }
};

int main() {
    Solution s;
    // string num1 = "123";
    // string num2 = "456";
    string num1 = "99";
    string num2 = "99";
    // string num1 = "9";
    // string num2 = "9";
    auto res = s.multiply(num1, num2);
    cout << res << endl;
    return 0;
}
