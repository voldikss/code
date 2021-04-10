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

class Solution {
  public:
    bool isUgly(int n) {
        if (n == 0) return false;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
                continue;
            } else if (n % 3 == 0) {
                n /= 3;
                continue;
            } else if (n % 5 == 0) {
                n /= 5;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {

    return 0;
}
