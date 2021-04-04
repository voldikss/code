#include <algorithm>
#include <cassert>
#include <bitset>
#include <climits>
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

const int capacity = 80000;
const int sep = 40000;

// 绝了
class Solution {
  public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<capacity> bs;
        bs.reset();
        bs[sep] = 1;

        for (const int& x : stones)
            bs = (bs << x | bs >> x);

        for (int i = 0; i < sep; i++) {
            if (bs[sep + i] == 1) return i;
        }

        return 0;
    }
};

int main(int argc, char** argv) {

    return 0;
}
