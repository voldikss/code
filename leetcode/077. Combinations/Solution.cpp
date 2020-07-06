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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        this->dfs(n, k, 1, {}, res);
        return res;
    }

    void dfs(int n, int k, int start, vector<int> path, vector<vector<int>> &res) {
        if (path.size() > k) return;

        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i + 1, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    cout << s.combine(4, 2) << endl;
    return 0;
}
