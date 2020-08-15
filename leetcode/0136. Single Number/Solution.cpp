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
#include <variant>
#include <vector>
using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (auto n : nums) res ^= n;
        return res;
    }
};

int main() {

    return 0;
}
