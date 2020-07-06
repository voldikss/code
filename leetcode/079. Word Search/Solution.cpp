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
#include <vector>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const list<T> &l) {
    for (auto &i : l) os << i << " ";
    return os;
}

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
    vector<vector<int>> path;

  public:
    void trace() {
        for (auto &p : path) {
            cout << "{" << p[0] << ", " << p[1] << "} ";
        }
    }

    bool exist(vector<vector<char>> &board, string word) {
        if (board.size() == 1 && board[0].size() == 1) {
            return word.size() == 1 && board[0][0] == word[0];
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    if (word.size() == 1) return true;
                    map<vector<int>, bool> used;
                    used[{i, j}] = true;
                    if (dfs(board, i, j, word, 0, used)) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int m, int n, string word, int x, map<vector<int>, bool> &used) {
        vector<vector<int>> coors = {{m - 1, n}, {m, n - 1}, {m, n + 1}, {m + 1, n}};
        for (auto &co : coors) {
            int i = co[0];
            int j = co[1];
            if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) continue;
            if (used[{i, j}] == true) continue;
            if (board[i][j] == word[x + 1]) {
                used[{i, j}] = true;
                if (x + 1 == word.size() - 1) return true;
                if (dfs(board, i, j, word, x + 1, used)) {
                    return true;
                } else {
                    used[{i, j}] = false;
                }
            }
        }
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

    // vector<vector<char>> board = {{'a'}};
    // auto res = s.exist(board, "a");

    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'E', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    auto res = s.exist(board, "ABCESEEEFS");

    cout << "-----------------------" << endl;
    cout << res << endl;
    // cout << s.exist(board, "ABCB") << endl;
    return 0;
}
