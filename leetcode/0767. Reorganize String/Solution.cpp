//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    string reorganizeString(string S) {
        string res = "";
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (char c : S) ++m[c];
        for (auto i : m) {
            if (i.second > (S.size() / 2) + 1) {
                return "";
            } else {
                q.push({i.second, i.first});
            }
        }

        while (q.size() >= 2) {
            auto c1 = q.top();
            q.pop();
            auto c2 = q.top();
            q.pop();
            res.push_back(c1.second);
            res.push_back(c2.second);
            if (--c1.first > 0) q.push(c1);
            if (--c2.first > 0) q.push(c2);
        }

        if (q.size() > 0) res.push_back(q.top().second);
        q.pop();
        return res;
    }
};

int main() {
    Solution s;
    string input = "aab";
    string res = s.reorganizeString(input);
    cout << res << endl;
    return 0;
}
