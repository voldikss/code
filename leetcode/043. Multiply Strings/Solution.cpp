#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

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
    string multiply(string num1, string num2) {
        vector<int> nums(num1.size() + num2.size(), 0);
        int tail1 = num1.size() - 1;
        int tail2 = num2.size() - 1;
        int tail = nums.size() - 1;
        int p1, p2, p;
        int n1, n2, n;
        int flag, carry;
        for (p2 = num2.size() - 1; p2 >= 0; p2--) {
            n2 = num2[p2] - '0';
            flag = 0;
            carry = 0;
            for (p1 = num1.size() - 1; p1 >= 0; p1--) {
                n1 = num1[p1] - '0';
                n = n1 * n2 + flag;
                // cout << n1 << " " << n2 << " " << n << endl;
                p = tail - (tail1 - p1 + tail2 - p2);
                nums[p] += (n % 10 + carry);
                carry = nums[p] / 10;
                nums[p] %= 10;
                flag = n / 10;
                // cout << nums << endl;
            }
            if (flag) nums[p - 1] = flag;
            if (carry) nums[p - 1] += 1;
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
