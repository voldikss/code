#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        triangle[1][0] += triangle[0][0];
        triangle[1][1] += triangle[0][0];
        if (triangle.size() == 2) return min(triangle[1][0], triangle[1][1]);

        for (int i = 2; i < triangle.size(); i++) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j < i; j++)
                triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
        }
        return *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
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
