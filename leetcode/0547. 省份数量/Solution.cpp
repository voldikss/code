#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class UnionFind {
  public:
    unordered_map<int, int> m;
    int num_of_sets = 0;

    void add(int x) {
        if (m.count(x) == 0) {
            m[x] = -1;
            num_of_sets++;
        }
    }

    void merge(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root != y_root) {
            m[x_root] = y_root;
            num_of_sets--;
        }
    }

    // find root
    int find(int x) {
        int root = x;
        while (m[root] != -1) root = m[root];
        if (root != x) m[x] = root;
        return root;
    }

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
  public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf;
        for (int i = 0; i < n; i++) uf.add(i);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) continue;
                if (isConnected[i][j]) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.num_of_sets;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<vector<int>> isConnected{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    vector<vector<int>> isConnected{{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
    auto res = s.findCircleNum(isConnected);
    cout << res << endl;
    return 0;
}
