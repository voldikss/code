#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> hashmap;
        for (const auto& kv : knowledge) hashmap[kv[0]] = kv[1];
        string sub;
        string ans;
        int index = 0;
        bool start_record = false;
        while (index < s.size()) {
            char ch = s[index];
            switch (ch) {
            case '(':
                //
                start_record = true;
                break;
            case ')':
                if (hashmap[sub].empty()) {
                    ans += "?";
                } else {
                    ans += hashmap[sub];
                }
                sub.erase();
                start_record = false;
                break;
            default:
                if (start_record) {
                    sub += ch;
                } else {
                    ans += ch;
                }
                break;
            }
            index++;
        }
        return ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}
