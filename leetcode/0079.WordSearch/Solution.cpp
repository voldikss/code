#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> path;

  public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                map<vector<int>, bool> used;
                if (dfs(board, i, j, word, 0, used)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int m, int n, string word, int x, map<vector<int>, bool>& used) {
        if (board[m][n] != word[x]) return false;
        if (x >= word.size() - 1) return true;
        used[{m, n}] = true;

        vector<vector<int>> coors = {{m - 1, n}, {m, n - 1}, {m, n + 1}, {m + 1, n}};
        for (auto& co : coors) {
            int i = co[0];
            int j = co[1];
            if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) continue;
            if (used[{i, j}] == true) continue;
            if (dfs(board, i, j, word, x + 1, used)) return true;
        }

        used[{m, n}] = false;
        return false;
    }
};

int main() {
    Solution s;
    // vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
    //                               {'S', 'F', 'C', 'S'},
    //                               {'A', 'D', 'E', 'E'}};
    // auto res = s.exist(board, "ABCCED");
    // auto res = s.exist(board, "SEE");
    // auto res = s.exist(board, "ABCB");

    vector<vector<char>> board = {{'a', 'a'}};
    auto res = s.exist(board, "aa");

    // vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
    //                               {'S', 'F', 'E', 'S'},
    //                               {'A', 'D', 'E', 'E'}};
    // auto res = s.exist(board, "ABCESEEEFS");

    cout << "-----------------------" << endl;
    cout << res << endl;
    // cout << s.exist(board, "ABCB") << endl;
    return 0;
}
