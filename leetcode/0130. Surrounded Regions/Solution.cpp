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
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;
        for (int i = 0; i < m; i++) {
            this->dfs(board, i, 0);
            this->dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            this->dfs(board, 0, i);
            this->dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int x, int y) {
        if (board[x][y] == 'O') {
            board[x][y] = '#';
            if (x - 1 >= 0 && board[x - 1][y] == 'O') {
                this->dfs(board, x - 1, y);
            }
            if (x + 1 < board.size() && board[x + 1][y] == 'O') {
                this->dfs(board, x + 1, y);
            }
            if (y - 1 >= 0 && board[x][y - 1] == 'O') {
                this->dfs(board, x, y - 1);
            }
            if (y + 1 < board[0].size() && board[x][y + 1] == 'O') {
                this->dfs(board, x, y + 1);
            }
        }
    }
};

int main() {
    Solution s;
    // vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
    //                               {'X', 'O', 'O', 'X'},
    //                               {'X', 'X', 'O', 'X'},
    //                               {'X', 'O', 'X', 'X'}};
    vector<vector<char>> board = {{}};
    s.solve(board);
    cout << board << endl;
    return 0;
}
