#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        int spare = 0;
        int minSpare = INT_MAX;
        int minSpareId = 0;

        for (int i = 0; i < length; i++) {
            spare += gas[i] - cost[i];
            if (spare < minSpare) {
                minSpare = spare;
                minSpareId = i;
            }
        }

        if (spare < 0) {
            return -1;
        } else {
            return (minSpareId + 1) % length;
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
