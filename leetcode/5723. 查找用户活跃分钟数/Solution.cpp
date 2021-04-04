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

class Solution {
  public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            if (a[0] < b[0])
                return true;
            else if (a[0] > b[0])
                return false;
            else if (a[1] < b[1])
                return true;
            else
                return false;
        });
        // cout << logs << endl;
        unordered_map<int, int> kv;
        for (int i = 0; i < logs.size(); i++) {
            if (i > 0 && logs[i - 1] == logs[i]) continue;
            kv[logs[i][0]]++;
        }
        vector<int> ans(k);
        for (auto& x : kv) {
            // cout << x << endl;
            ans[x.second - 1]++;
        }
        return ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}
