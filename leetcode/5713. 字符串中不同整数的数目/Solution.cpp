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
#include <vector>
using namespace std;

#define isletter(ch) (ch >= 'a' && ch <= 'z')
#define isposnum(ch) (ch >= '1' && ch <= '9')

#define isletter(ch) (ch >= 'a' && ch <= 'z')
#define isposnum(ch) (ch >= '1' && ch <= '9')

class Solution {
  public:
    int numDifferentIntegers(string word) {
        map<string, bool> hashmap;
        int index = 0;
        int len = word.size();
        string str;
        int ans = 0;
        while (index < len) {
            char ch = word[index];
            if (ch == '0') {
                if (!str.empty()) {
                    str.push_back(ch);
                }
            } else if (isletter(ch)) {
                if (!str.empty()) {
                    if (hashmap[str] == false) {
                        hashmap[str] = true;
                        ans++;
                    }
                    str.erase();
                } else {
                    if (index > 0 && word[index - 1] == '0' && !hashmap["0"]) {
                        hashmap["0"] = true;
                        ans++;
                    }
                }
            } else {
                str.push_back(ch);
            }
            index++;
        }
        if (!str.empty()) {
            if (hashmap[str] == false) {
                hashmap[str] = true;
                ans++;
            }
            str.erase();
        } else {
            if (index > 0 && word[index - 1] == '0' && !hashmap["0"]) {
                hashmap["0"] = true;
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
}
