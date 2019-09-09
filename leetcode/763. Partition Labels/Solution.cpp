//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        map<char, int> lastPos;
        for (int p = 0; p < S.size(); ++p) {
            lastPos[S[p]] = p;
        }

        int begin = 0;
        int end = 0;
        for (int p = 0; p < S.size(); ++p) {
            end = max(end, lastPos[S[p]]);
            if (end == p) {
                res.push_back(end - begin + 1);
                begin = end + 1;
            }
        }
        return res;
    }
};

int main() {
    string input = "ababcbacadefegdehijhklij";
    Solution s;
    vector<int> res = s.partitionLabels(input);
    for (auto r : res) cout << r << endl;
    return 0;
}
