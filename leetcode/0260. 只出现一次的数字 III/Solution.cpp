#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorall = 0;
        for (const auto& x : nums) xorall ^= x;
        int count = 0;
        // cout << "xorall ->" << xorall;
        while (xorall != 1) {
            xorall = (int)((unsigned int)xorall >> 1);
            cout << "count: " << count;
            count++;
        }
        xorall <<= count;
        int n1 = 0;
        int n2 = 0;
        for (const auto& x : nums) {
            // printf("x = %d, xorall= %d, x & xorall = %d\n", x, xorall, x & xorall);
            if ((x & xorall) == 0) {
                n1 ^= x;
                // cout << "n1: " << x << endl;
            } else {
                n2 ^= x;
                // cout << "n2: " << x << endl;
            }
        }
        return {n1, n2};
    }
};

int main(int argc, char** argv) {

    return 0;
}
