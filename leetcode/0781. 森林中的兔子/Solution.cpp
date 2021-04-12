#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> kv;
        int ans = 0;
        for (const auto& x : answers) {
            if (x == 0)
                ans++;
            else
                kv[x]++;
        }
        for (auto& p : kv) {
            if (p.second <= p.first + 1) {
                ans += p.first + 1;
            } else {
                while (p.second > p.first) {
                    ans += p.first + 1;
                    p.second -= (p.first + 1);
                }
                if (p.second != 0)
                    ans += p.first + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}
