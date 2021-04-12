#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string getPermutation(int n, int k) {
        k--;

        vector<int> factorial(n, 1);
        for (int i = 2; i <= n; i++)
            factorial[i] = i * factorial[i - 1];

        // 此处用 vector 也没啥，毕竟只有 1-9 个数字而已
        // 因此在 ./Solution3.cpp 中转而用了 vector
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
