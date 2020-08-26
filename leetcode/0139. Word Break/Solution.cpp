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
    bool wordBreak(string s, vector<string> &wordDict) {
        set<string> hashSet;
        for (auto &w : wordDict) {
            hashSet.insert(w);
        }
        map<int, bool> cache;
        return this->helper(s, 0, hashSet, cache);
    }

    bool helper(string &s, int start, set<string> &hashSet, map<int, bool> &cache) {
        if (start == s.size()) {
            return true;
        }
        if (cache.find(start) != cache.end()) {
            return cache[start];
        }
        for (int i = start + 1; i <= s.size(); i++) {
            string head = s.substr(start, i - start);
            bool found = hashSet.find(head) != hashSet.end();
            if (found && this->helper(s, i, hashSet, cache)) {
                cache[start] = true;
                return true;
            }
        }
        cache[start] = false;
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
