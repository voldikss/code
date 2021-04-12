#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorall = 0;
        for (const auto& x : nums) xorall ^= x;
        int count = 0;
        // 不断右移来获取1所在的最高位，原来 C++ 是算术右移！
        while (xorall != 1) {
            xorall = (int)((unsigned int)xorall >> 1);
            cout << "count: " << count;
            count++;
        }
        // 再左移回去，即可作为 mask
        xorall <<= count;
        int n1 = 0;
        int n2 = 0;
        for (const auto& x : nums) {
            if ((x & xorall) == 0) {
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
