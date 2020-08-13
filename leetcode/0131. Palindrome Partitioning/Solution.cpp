#include "../../vital/vector.cpp"
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
        vector<string> path;
        this->helper(res, path, s);
        return res;
    }

    void helper(vector<vector<string>> &res, vector<string> &path, string ss) {
        if (ss.empty()) {
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= ss.size(); i++) {
            string head = ss.substr(0, i);
            string tail = ss.substr(i, ss.size());
            if (!this->isPalindrom(head)) continue;
            path.push_back(head);
            this->helper(res, path, tail);
            path.pop_back();
        }
    }

    bool isPalindrom(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    // cout << s.partition("aab") << endl;
    // cout << s.partition("a") << endl;
    cout << s.partition("") << endl;
    return 0;
}
