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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        res.emplace_back(vector<int>{1});
        if (numRows == 1) return res;
        for (int i = 2; i <= numRows; i++) {
            vector<int> tmp = res.back();
            vector<int> level(i, 1);
            for (int j = 0; j < tmp.size() - 1; j++) {
                level[j + 1] = tmp[j] += tmp[j + 1];
            }
            res.emplace_back(level);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.generate(5) << endl;
    return 0;
}
