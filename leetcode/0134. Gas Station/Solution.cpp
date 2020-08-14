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
        for (int i = 0; i < gas.size(); i++) {
            int res = this->check(i, gas, cost);
            if (res != -1) return res;
        }
        return -1;
    }

    int check(int station, vector<int> &gas, vector<int> &cost) {
        int remain = 0;
        int length = gas.size();
        int position = station;

        while (true) {
            remain += gas[position];
            remain -= cost[position];

            if (remain < 0) return -1;
            position++;
            position %= length;
            if (position == station) return station;
        }

        return -1;
    }
};

int main() {
    // vector<int> gas = {1, 2, 3, 4, 5};
    // vector<int> cost = {3, 4, 5, 1, 2};
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    Solution s;
    auto res = s.canCompleteCircuit(gas, cost);
    cout << res << endl;
    return 0;
}
