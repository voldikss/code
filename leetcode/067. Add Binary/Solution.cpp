#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

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
    string addBinary(string a, string b) {
        string res;
        int p1 = a.size() - 1;
        int p2 = b.size() - 1;

        int flag = 0;
        while (p1 >= 0 || p2 >= 0 || flag != 0) {
            if (p1 >= 0) flag += a[p1--] - '0';
            if (p2 >= 0) flag += b[p2--] - '0';
            res.push_back(flag % 2 + '0');
            flag /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    string a = "1010", b = "1011";
    auto res = s.addBinary(a, b);
    cout << res << endl;
    return 0;
}
