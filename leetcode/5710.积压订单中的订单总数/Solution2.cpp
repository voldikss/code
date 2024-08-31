#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

priority_queue<pair<int, int>> buy, sell;

class Solution {
  public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        for (const auto& order : orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];
            if (type == 0) {   // buy
                while (amount > 0 && !sell.empty()) {
                    pair<int, int> cur = sell.top();
                    if (-cur.first <= price) {
                        sell.pop();
                        int offset = min(cur.second, amount);
                        amount -= offset;
                        cur.second -= offset;
                        if (cur.second > 0) {
                            sell.push(make_pair(cur.first, cur.second));
                        }
                    } else
                        break;
                }
                if (amount > 0) buy.push(make_pair(price, amount));
            } else {   // sell
                while (amount > 0 && !buy.empty()) {
                    pair<int, int> cur = buy.top();
                    if (cur.first >= price) {
                        buy.pop();
                        int offset = min(cur.second, amount);
                        amount -= offset;
                        cur.second -= offset;
                        if (cur.second > 0) {
                            buy.push(make_pair(cur.first, cur.second));
                        }
                    } else
                        break;
                }
                if (amount > 0) sell.push(make_pair(-price, amount));
            }
        }
        int ans = 0;
        while (!buy.empty()) {
            ans += buy.top().second;
            ans %= MOD;
            buy.pop();
        }
        while (!sell.empty()) {
            ans += sell.top().second;
            ans %= MOD;
            sell.pop();
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> orders{{10, 5, 0}, {15, 2, 1}, {25, 1, 1}, {30, 4, 0}};
    auto res = s.getNumberOfBacklogOrders(orders);
    cout << res << endl;
    return 0;
}
