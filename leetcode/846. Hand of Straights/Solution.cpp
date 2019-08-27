//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int W) {
    if (hand.size() % W != 0) return false;
    sort(hand.begin(), hand.end());

    map<int, int> hashMap;
    for (int i = 0; i < hand.size(); ++i) {
      hashMap[hand[i]]++;
    }

    set<int> nums;
    for (int i = 0; i < hand.size(); ++i) {
      nums.insert({hand[i]});
    }
    // for (set<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
    // {
    //   cout << *iter << " " << hashMap[*iter]<< endl;
    // }
    for (set<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
      int num = *iter;
      if (hashMap[num] > 0) {
        int need = hashMap[num];
        for (int i = 1; i < W; ++i) {
          if (hashMap[num + i] >= need) {
            hashMap[num + i] -= need;
          } else {
            return false;
          }
        }
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  int W = 3;
  s.isNStraightHand(hand, W);
}
