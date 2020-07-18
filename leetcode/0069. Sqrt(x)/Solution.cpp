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
        long left = 0;
        long right = x;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long res = mid * mid;
            if (res > x) {
                right = mid - 1;
            } else if (res < x) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return right;   // miao a! Here right must less equal than left since `while (left <= right)`
    }
};

int main() {
    Solution s;
    // cout << s.mySqrt(0) << endl;
    cout << s.mySqrt(2147395599) << endl;
    return 0;
}
