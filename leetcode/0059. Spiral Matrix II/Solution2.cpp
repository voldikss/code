#include "../../include/vector.hpp"
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

enum class State {
    right,
    down,
    left,
    up,
};

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        auto res = vector<vector<int>>(n, vector<int>(n, -1));
        State state = State::right;

        int total = n * n;
        int x = 0;
        int y = 0;

        for (int i = 1; i <= total; i++) {
            if (i == 0) break;
            res[y][x] = i;
            switch (state) {
            case State::right:   // right or down
                if (x + 1 < n && res[y][x + 1] == -1) {
                    x++;
                    break;
                }
                if (y + 1 < n && res[y + 1][x] == -1) {
                    state = State::down;
                    y++;
                    break;
                }
            case State::down:
                if (y + 1 < n && res[y + 1][x] == -1) {
                    y++;
                    break;
                }
                if (x - 1 > -1 && res[y][x - 1] == -1) {
                    state = State::left;
                    x--;
                    break;
                }
            case State::left:
                if (x - 1 > -1 && res[y][x - 1] == -1) {
                    x--;
                    break;
                }
                if (y - 1 > -1 && res[y - 1][x] == -1) {
                    state = State::up;
                    y--;
                    break;
                }
            case State::up:
                if (y - 1 > -1 && res[y - 1][x] == -1) {
                    y--;
                    break;
                }
                if (x + 1 < n && res[y][x + 1] == -1) {
                    state = State::right;
                    x++;
                    break;
                }
            default:
                break;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    auto res = s.generateMatrix(3);
    cout << res << endl;
    // for (int n = 1; n <= 10; n++) {
    //     auto res = s.generateMatrix(n);
    //     cout << res << endl;
    // }
    return 0;
}
