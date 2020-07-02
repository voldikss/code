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
    string getPermutation(int n, int k) {
        k--;

        vector<int> factorial(n, 1);
        for (int i = 2; i <= n; i++)
            factorial[i] = i * factorial[i - 1];

        list<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        string res;
        // i is the depth
        for (int i = n - 1; i >= 0; i--) {
            int idx = k / factorial[i];
            cout << k << " " << factorial[i] << " " << idx << endl;
            auto it = nums.begin();
            advance(it, idx);
            res.push_back(*it + '0');
            nums.erase(it);
            k -= idx * factorial[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3, 3) << endl;
    // cout << s.getPermutation(4, 9) << endl;
    return 0;
}
