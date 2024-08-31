#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

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
