#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++) res += max(prices[i + 1] - prices[i], 0);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> prices = {};
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
