#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string getPermutation(int n, int k) {
        k--;

        vector<int> factorial(n, 1);
        for (int i = 1; i < n; i++)
            factorial[i] = factorial[i - 1] * i;

        vector<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        string res;
        while (n--) {
            int m = k / factorial[n];
            res.push_back(nums[m]);
            nums.erase(nums.begin() + m);
            k %= factorial[n];
        }
        return res;
    }
};

int main() {
    Solution s;
    // cout << s.getPermutation(3, 3) << endl;
    cout << s.getPermutation(4, 9) << endl;
    return 0;
}
