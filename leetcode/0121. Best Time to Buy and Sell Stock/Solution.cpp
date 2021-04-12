#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min = prices[0];
        int max = 0;
        for (auto p : prices) {
            if (p - min > max) max = p - min;
            if (p < min) min = p;
        }
        return max;
    }
};

int main() {
    Solution s;
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
