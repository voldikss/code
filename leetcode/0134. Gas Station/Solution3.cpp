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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int remain = 0;
        int position = 0;
        int length = gas.size();

        for (int i = 0; i < length; i++) {
            total += gas[i] - cost[i];
            remain += gas[i] - cost[i];
            if (remain < 0) {
                remain = 0;
                // 如果存在满足条件的位置，则该位置不可能是最后一站
                // 因为如果是最后一站，那么说明前面的站都无法满足
                // 故而 total < 0，即不存在满足条件的位置
                position = i + 1;
            }
        }
        if (total < 0) {
            return -1;
        } else {
            return position;
        }
    }
};

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    // vector<int> gas = {2, 3, 4};
    // vector<int> cost = {3, 4, 3};
    Solution s;
    auto res = s.canCompleteCircuit(gas, cost);
    cout << res << endl;
    return 0;
}
