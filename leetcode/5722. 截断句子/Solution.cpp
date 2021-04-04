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
