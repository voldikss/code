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
    int lengthOfLastWord(string s) {
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                res++;
            } else if (res != 0) {
                return res;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    // auto res = s.lengthOfLastWord("hello world");
    // auto res = s.lengthOfLastWord("hello world  ");
    // auto res = s.lengthOfLastWord("hello me");
    auto res = s.lengthOfLastWord("a");
    // auto res = s.lengthOfLastWord("hello");
    cout << res << endl;
    return 0;
}
