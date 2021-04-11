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
    int arraySign(vector<int>& nums) {
        bool ispositive = true;
        for (const auto& x : nums) {
            if (x == 0) return 0;
            if (x < 0) ispositive = !ispositive;
        }
        if (ispositive) return 1;
        else return -1;
    }
};

int main(int argc, char** argv) {
    
    return 0;
}
