#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> hashSet;
        for (auto& w : wordDict) {
            hashSet.insert(w);
        }
        vector<int> cache(s.length(), -1);
        return this->helper(s, 0, hashSet, cache);
    }

    bool helper(string& s, int start, set<string>& hashSet, vector<int>& cache) {
        if (start == s.size()) {
            return true;
        }
        if (cache[start] != -1) {
            return cache[start];
        }
        for (int i = start + 1; i <= s.size(); i++) {
            string head = s.substr(start, i - start);
            bool found = hashSet.find(head) != hashSet.end();
            if (found && this->helper(s, i, hashSet, cache)) {
                cache[start] = 1;
                return true;
            }
        }
        cache[start] = 0;
        return false;
    }
};

int main() {
    Solution s;
    // string str = "leetcode";
    // vector<string> wordDict = {"leet", "code"};
    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    cout << s.wordBreak(str, wordDict) << endl;
    return 0;
}
