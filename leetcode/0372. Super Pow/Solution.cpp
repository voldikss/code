#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int superPow(int a, vector<int>& b) {
        int phi = Phi(1337);
        int exp = 0;
        for (int i : b) {
            exp = (exp * 10 + i) % phi;
        }
        return quickPow(a, exp, 1337);
    }

    int quickPow(int a, int b, int c) {
        if (a == 1) return 1 % c;
        if (b == 1) return a % c;
        if (a == 0) return 0 % c;
        if (b == 0) return 1 % c;
        return (quickPow(a, b / 2, c) % 1337) * (quickPow(a, b - b / 2, c) % 1337) %
               1337;
    }

    // 使用循环实现
    int quickPowMod2(int a, int b) {
        int ans = 1;
        while (b) {
            if (b % 2 == 1) {
                b--;
                ans *= a;
            } else {
                a = a * a;
                b /= 2;
            }
        }
        return ans;
    }

    int Phi(int n) {
        int phi = n;
        for (int i = 2; i * i < n; ++i) {
            if (n % i == 0) phi = phi - phi / i;
            while (n % i == 0) n = n / i;
        }
        if (n > 1) phi = phi - phi / n;
        return phi;
    }
};

int main() {
    Solution s;
    int ol = s.Phi(1337);
    cout << ol << endl;
    return 0;
}
