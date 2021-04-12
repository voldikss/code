#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (const auto& x : stones) q.push(x);
        while (!q.empty()) {
            int x = q.top();
            q.pop();
            if (q.empty()) return x;
            int y = q.top();
            q.pop();
            if (x != y) {
                q.push(abs(x - y));
            }
        }
        return 0;
    }
};

int main(int argc, char** argv) {

    return 0;
}
