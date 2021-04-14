#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param N int整型
     * @return int整型vector
     */

    vector<int> numberOfShelves(int n) {
        vector<vector<int>> triangle(n, vector<int>(n));
        helper(triangle, n, 0, 1);
        cout << triangle << endl;
        int len = n * (n + 1) / 2;
        vector<int> res(len);
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                res[index++] = triangle[i][j];
            }
        }
        cout << res.size() << endl;
        return res;
    }

    void helper(vector<vector<int>>& triangle, int n, int x, int index) {
        if (n <= 0) return;
        for (int i = x; i < x + n; i++) {
            triangle[i][x] = index++;
        }
        index--;   // 5
        for (int i = 0; i < n; i++) {
            triangle[x + n - 1 - i][x + i] = index++;
        }
        index--;
        for (int i = x + n - 1; i > x; i--) {
            triangle[x][i] = index++;
        }
        helper(triangle, n - 3, x + 1, index);
    }
};

int main(int argc, char** argv) {
    Solution s;
    int n = 5;
    auto res = s.numberOfShelves(n);
    cout << res << endl;
    return 0;
}
