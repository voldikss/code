#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define LL long long

class Solution {
  public:
    int orchestraLayout(LL num, LL x, LL y) {
        int padding = min(min(num - 1 - x, x), min(num - 1 - y, y));
        LL total = 0;
        int index = 0;
        // while (index < padding) {
        //     total += (4*(num-1));
        //     index++;
        //     num -= 2;
        // }
        total += (4 * padding * (num - padding));
        num -= 2 * padding;
        x -= padding;
        y -= padding;
        if (x == 0)
            total += (y + 1);
        else if (x == num - 1)
            total += (num + num - 1 + num - 1 - y);
        else if (y == 0)
            total += (4 * (num - 1) - x + 1);
        else
            total += (num + x);

        int ans = total % 9;
        return ans == 0 ? 9 : ans;
    }
};

int main(int argc, char** argv) {

    return 0;
}
