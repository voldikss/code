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

enum class State {
    right,
    down,
    left,
    up,
};

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int width = matrix[0].size();
        int height = matrix.size();
        auto visited = vector<vector<bool>>(height, vector<bool>(width, false));
        State state = State::right;
        int x = -1;
        int y = 0;

        while (true) {
            switch (state) {
            case State::right:
                if (x + 1 < width && !visited[y][x + 1]) {
                    x++;
                    res.push_back(matrix[y][x]);
                    visited[y][x] = INT_MAX;
                    break;
                }
                if (y + 1 < height && !visited[y + 1][x]) {
                    state = State::down;
                    break;
                }
            case State::down:
                if (y + 1 < height && !visited[y + 1][x]) {
                    y++;
                    res.push_back(matrix[y][x]);
                    visited[y][x] = INT_MAX;
                    break;
                }
                if (x - 1 > -1 && !visited[y][x - 1]) {
                    state = State::left;
                    break;
                }
            case State::left:
                if (x - 1 > -1 && !visited[y][x - 1]) {
                    x--;
                    res.push_back(matrix[y][x]);
                    visited[y][x] = INT_MAX;
                    break;
                }
                if (y - 1 > -1 && !visited[y - 1][x]) {
                    state = State::up;
                    break;
                }
            case State::up:
                if (y - 1 > -1 && !visited[y - 1][x]) {
                    y--;
                    res.push_back(matrix[y][x]);
                    visited[y][x] = INT_MAX;
                    break;
                }
                if (x + 1 < width && !visited[y][x + 1]) {
                    state = State::right;
                    break;
                }
            default:
                return res;
                // end
                break;
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    auto matrix = vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = s.spiralOrder(matrix);
    cout << res << endl;
    return 0;
}
