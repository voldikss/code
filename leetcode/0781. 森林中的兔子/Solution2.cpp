#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/// Ref: https://leetcode-cn.com/problems/rabbits-in-forest/solution/fu-xue-ming-zhu-zhao-gui-lu-fu-xiang-sha-1yk3/
class Solution {
  public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> kv;
        int ans = 0;
        for (const auto& x : answers) kv[x]++;
        for (const auto& p : kv) {
            ans += ceil((p.second) * 1.0 / (p.first + 1)) * (p.first + 1);
        }
        return ans;
    }
};


int main(int argc, char** argv) {

    return 0;
}
