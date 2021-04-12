#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        map<char, int> hash_map;
        for (char c : chars) hash_map[c]++;
        for (string s : words) {
            bool flag = true;
            map<char, int> m = hash_map;
            for (char cc : s) {
                m[cc]--;
                // XXX: 省去判断 m has cc 的麻烦
                if (m[cc] < 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) res += s.size();
        }
        return res;
    }
};
