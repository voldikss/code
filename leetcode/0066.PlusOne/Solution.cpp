#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0) {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
            i--;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// 偶然在解题区看到的一个解法，这个应该是 cpp 里面最短的了吧 Orz
// class Solution2 {
//   public:
//     vector<int> plusOne(vector<int> &digits) {
//         for (int i = digits.size() - 1; i >= 0; --i)
//             if ((++digits[i] %= 10) != 0) return digits;
//         digits.insert(digits.begin(), 1);
//         return digits;
//     }
// };

int main() {
    Solution s;
    vector<int> digits{1, 2, 3};
    // vector<int> digits{9, 9, 9};
    auto res = s.plusOne(digits);
    cout << res << endl;
    return 0;
}
