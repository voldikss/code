#include "../../include/vector.cpp"
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
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        int row = A.size();
        if (row == 0) return {};
        int col = A[0].size();
        if (col == 0) return {};
        vector<vector<int>> res;
        for (int i = 0; i < col; i++) {
            vector<int> tmp;
            for (int j = 0; j < row; j++) {
                tmp.push_back(A[j][i]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};
    Solution s;
    auto res = s.transpose(matrix);
    cout << res << endl;
    return 0;
}
