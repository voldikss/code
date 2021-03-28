#include "../../include/vector.hpp"
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
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i].size(); j++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};

int main() {
    Solution s;
    // vector<vector<int>> triangle = {{-1},
    //                                 {3, 2},
    //                                 {-3, 1, -1}};
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}
