#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string truncateSentence(string s, int k) {
        int len = s.size();
        int index = 0;
        while (index < len) {
            switch (s[index]) {
            case ' ':
                if (s[index - 1] == ' ') break;
                k--;
                if (k == 0)
                    return s.substr(0, index);
                break;
            default:
                //
                break;
            }
            index++;
        }
        return s;
    }
};

int main(int argc, char** argv) {

    return 0;
}
