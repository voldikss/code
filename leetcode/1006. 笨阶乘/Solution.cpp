#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int clumsy(int N) {
        int res = 0;
        int index = 0;
        int tmp = 0;
        while (true) {
            int mod = index % 4;
            int cur = N - index;
            switch (mod) {
            case 0:
                tmp = cur;
                break;
            case 1:
                tmp *= cur;
                break;
            case 2:
                tmp /= cur;
                break;
            case 3:
                tmp = cur;
                break;
            default:
                break;
            }
            if (index == N - 1) {
                if (mod == 3)
                    res += tmp;
                else if (index < 3)
                    res += tmp;
                else
                    res -= tmp;
                break;
            } else if (mod == 2) {
                if (index < 3)
                    res += tmp;
                else
                    res -= tmp;
            } else if (mod == 3) {
                res += tmp;
            }
            index++;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int N = 4;
    auto res = s.clumsy(N);
    cout << res << endl;
    return 0;
}
