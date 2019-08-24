// ============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
// ============================================================================

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    if (words.size() == 1) {
      return words[0].size() + 1;
    }
    // initialize
    for (int i = 0; i < words.size(); ++i) {
      reverse(words[i].begin(), words[i].end());
    }
    sort(words.begin(), words.end());

    int ans = 0;
    string curr;
    string next;
    for (int i = 0; i < words.size() - 1; ++i) {
      curr = words[i];
      next = words[i + 1];
      if (!match(curr, next)) {
        ans += curr.size() + 1;
      }
    }
    return ans + next.size() + 1;
  }

  /* word1.size() <= word2.size() */
  bool match(string word1, string word2) {
    bool matched = true;
    for (int i = 0; i < word1.size(); ++i) {
      if (word1[i] != word2[i]) {
        matched = false;
      }
    }
    return matched;
  }
};

int main() {
  Solution s;
  vector<string> words = {"time", "me", "bell"};
  // for (auto i : words) cout << i << endl;

  cout << s.minimumLengthEncoding(words) << endl;
  // cout << s.match("em", "emit") << endl;
}
