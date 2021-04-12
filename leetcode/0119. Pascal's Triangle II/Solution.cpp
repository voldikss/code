#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.emplace_back(1);
        if (rowIndex == 0) return res;
        while (rowIndex--) {
            res.emplace_back(0);
            vector<int> tmp(res);
            for (int j = 1; j < res.size(); j++) res[j] += tmp[j - 1];
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getRow(4) << endl;
    return 0;
}
