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

template <typename T>
ostream &operator<<(ostream &os, const list<T> &l) {
    for (auto &i : l) os << i << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto x : vec) os << x << " ";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vec) {
    for (auto &x : vec) os << x << endl;
    return os;
}

class Solution {
  public:
    int mySqrt(int x) {
        double curr = 10;
        while (true) {
            double prev = curr;
            curr = 1 / 2.0 * (prev + x / prev);
            if ((int)prev == (int)curr) break;
        }
        return curr;
    }
};

int main() {
    Solution s;
    // cout << s.mySqrt(0) << endl;
    cout << s.mySqrt(2147395599) << endl;
    // cout << s.mySqrt(16) << endl;
    return 0;
}
