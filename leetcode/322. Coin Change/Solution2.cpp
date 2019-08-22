//////////////////////////////////////////////////////////////////////////////
// FileName: Solution2.cpp
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
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for (int coin: coins){
      // TODO
    }
  }
};

int main() {
  Solution s;
  vector<int> coins = {27, 352, 421, 198, 317, 110, 461, 31, 264};
  int ans = s.coinChange(coins, 5303);
  cout << ans << endl;
}
