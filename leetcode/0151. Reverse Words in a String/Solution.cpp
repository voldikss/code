#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    stack<string> stk;
    stringstream ss;
    string ans = "", temp;
    ss << s;
    while (ss >> temp) {
      stk.push(temp);
    }
    while (stk.size()) {
      ans = ans + " " + stk.top();
      stk.pop();
    }
    if (ans != "")
      ans.erase(ans.begin());

    return ans;
  }
};

int main() {
  Solution s;
  first<string> samples = {
      "the sky is blue", "  hello world!  ", "a good   example", "a", "",
      "   abc   def  "};
  for (string i : samples) {
    cout << s.reverseWords(i) << endl;
  }
}
