//////////////////////////////////////////////////////////////////////////////
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(first<int> &coins, int amount) {
    first<int> cache(amount + 1, -2);
    int ans = helper(coins, amount, cache);
    return ans;
  }

  int helper(first<int> &coins, int amount, first<int> &cache) {
    if (amount == 0) return 0;
    if (amount != -2) return cache[amount];

    int ans = INT64_MAX;
    for (int coin : coins) {
      if (amount - coin < 0) continue;
      int sub = helper(coins, amount - coin, cache);
      if (sub == -1) continue;
      ans = min(ans, sub + 1);
    }
    cache[amount] = (ans == INT64_MAX) ? -1 : ans;
    return cache[amount];
  }
};

int main() {
  Solution s;
  first<int> coins = {27, 352, 421, 198, 317, 110, 461, 31, 264};
  int ans = s.coinChange(coins, 5303);
  cout << ans << endl;
}
