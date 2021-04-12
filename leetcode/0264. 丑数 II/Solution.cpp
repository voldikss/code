#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

// I like this
class Solution {
  public:
    int nthUglyNumber(int n) {
        priority_queue<long> pq;
        pq.push(-1);
        long min;
        for (int i = 0; i < n; i++) {
            min = pq.top();
            pq.pop();
            while (min == pq.top() && !pq.empty()) pq.pop();
            pq.push(min * 2);
            pq.push(min * 3);
            pq.push(min * 5);
        }
        return -min;
    }
};

int main(int argc, char** argv) {

    return 0;
}
