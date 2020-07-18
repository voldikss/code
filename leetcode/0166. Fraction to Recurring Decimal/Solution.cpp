//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  string fractionToDecimal(int64_t numerator, int64_t denominator) {
    // 预处理
    if (numerator == 0) return "0";

    int sign = 1;
    if (numerator < 0 ^ denominator < 0) sign = -1;

    numerator = abs(numerator);
    denominator = abs(denominator);

    // 预处理完毕
    string res;
    if (sign == -1) res += "-";
    res += to_string(numerator / denominator);
    if (numerator % denominator == 0) return res;
    res += ".";

    unordered_map<int64_t, int> hashMap;
    for (int64_t r = numerator % denominator; r; r %= denominator) {
      // if meet that remainder again
      if (hashMap.count(r) > 0) {
        res.insert(hashMap[r], "(");
        res += ")";
        break;
      }

      // 妙,此处并没有采用循环哨兵,而是直接 res.size() !
      hashMap[r] = res.size();

      r *= 10;

      res += to_string(r / denominator);
    }

    return res;
  }
};

int main() {
  Solution s;
  string res = s.fractionToDecimal(4, 3);
  cout << res << endl;
}
