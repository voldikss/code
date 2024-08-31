#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        int p = 0;
        int q = s.size() - 1;
        while (p < q) {
            while (!isalnum(s[p]) && p <= q) p++;
            while (!isalnum(s[q]) && p <= q) q--;

            if (p >= q) return true;
            if (isdigit(s[p])) {
                if (s[p++] != s[q++]) return false;
            } else {
                if (tolower(s[p++]) != tolower(s[q++])) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    // cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    // cout << s.isPalindrome("race a car") << endl;
    // cout << s.isPalindrome("0P") << endl;
    // cout << s.isPalindrome("pP") << endl;
    cout << s.isPalindrome(".,") << endl;
    return 0;
}
