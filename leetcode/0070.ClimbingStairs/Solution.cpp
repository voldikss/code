#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    map<int, int> hashMap;

  public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        map<int, int>::iterator pos = hashMap.find(n);

        if (pos != hashMap.end())
            return pos->second;
        else {
            int val = climbStairs(n - 2) + climbStairs(n - 1);
            hashMap[n] = val;
            return val;
        }
    }
};

int main() {
    Solution s;
    vector<int> samples = {44};
    // vector<int> samples = {1, 2, 3, 4, 44};
    for (int i : samples)
        cout << s.climbStairs(i) << endl;
}
