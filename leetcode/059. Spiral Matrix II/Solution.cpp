#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto x : vec) os << x << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vec) {
    for (auto &x : vec) os << x << endl;
    return os;
}

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        int i = 0;
        int j = 0;
        int di = 0;
        int dj = 1;
        int cnt = 0;
        for (int x = 0; x < n * n; x++) {
            res[i][j] = x + 1;
            if ((i == cnt && j == n - 1 - cnt) || (i == n - 1 - cnt && j == n - 1 - cnt) || (j == cnt && i == n - 1 - cnt)) {
                swap(di, dj);
                dj = -dj;
            }
            if (i == cnt + 1 && j == cnt) {
                cnt++;
                i = cnt;
                j = cnt;
                swap(di, dj);
                dj = -dj;
                // cout << i << j << endl;
            } else {
                i += di;
                j += dj;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    for (int n = 1; n <= 10; n++) {
        auto res = s.generateMatrix(n);
        cout << res << endl;
    }
    return 0;
}
