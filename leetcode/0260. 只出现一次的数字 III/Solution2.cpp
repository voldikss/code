#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

// 该解法提供了一种方便的寻找二进制1所在最低位的方法
class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned xorall = 0;
        for (const auto& x : nums) xorall ^= x;
        int mask = xorall & (-xorall);
        int n1 = 0;
        int n2 = 0;
        for (const auto& x : nums) {
            if ((x & mask) == 0) {
                n1 ^= x;
            } else {
                n2 ^= x;
            }
        }
        return {n1, n2};
    }
};

int main(int argc, char** argv) {

    return 0;
}
