#include "../../include/global.hpp"
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
    int numTrees(int n) {
        map<int, int> cache;
        return G(n, cache);
    }

    int G(int n, map<int, int> &cache) {
        if (n == 0 || n == 1) return 1;
        if (cache.count(n)) return cache.find(n)->second;
        int res = 0;
        for (int i = 1; i <= n; i++) res += F(i, n, cache);
        cache.insert(make_pair(n, res));
        return res;
    }

    int F(int i, int n, map<int, int> &cache) {
        return G(i - 1, cache) * G(n - i, cache);
    }
};

int main() {
    Solution s;
    cout << s.numTrees(3) << endl;
    // cout << s.numTrees(2) << endl;
    return 0;
}
