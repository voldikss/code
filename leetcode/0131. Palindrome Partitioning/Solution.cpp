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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int len = s.size();
        if (len == 0) {
            return res;
        }

        vector<vector<bool>> dp(len, vector<bool>(len));
        for (int j = 0; j < len; j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<string> path;
        this->helper(res, path, dp, s, 0, len);
        return res;
    }

    void helper(vector<vector<string>> &res, vector<string> &path, vector<vector<bool>> &dp, string s, int start, int len) {
        if (start == len) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < len; i++) {
            if (!dp[start][i]) {
                continue;
            }
            path.push_back(s.substr(start, i + 1 - start));
            this->helper(res, path, dp, s, i + 1, len);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    cout << s.partition("aab") << endl;
    // cout << s.partition("a") << endl;
    // cout << s.partition("") << endl;
    return 0;
}
