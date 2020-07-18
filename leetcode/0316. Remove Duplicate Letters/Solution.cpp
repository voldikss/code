//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char, int> hash_map;
        // 这个可以用 vector<char, bool> alreay_in(128, 0) 代替
        // 直接在定义的时候初始化
        unordered_map<char, bool> alreay_in;
        for (char c : s) {
            ++hash_map[c];
            alreay_in[c] = false;
        }

        for (char c : s) {
            // 每个字符只访问/进/出各一次，所以访问到即减一
            --hash_map[c];

            if (alreay_in[c]) continue;

            while (hash_map[res.back()] && res.back() > c) {
                alreay_in[res.back()] = false;
                res.pop_back();
            }

            res.push_back(c);
            alreay_in[c] = true;
        }
        return res;
    }
};

int main() {
    // string str = "bcabc";
    // string str = "cbacdcbc";
    // string str = "bbcaac";
    string str = "edebbed";
    Solution s;
    string res = s.removeDuplicateLetters(str);
    cout << res << endl;
    return 0;
}
