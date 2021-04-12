#include <bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/largest-number/solution/c-4ms-by-harold-15/
class Solution {
  public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        if (std::all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return "0";
        }
        vector<string> strnums(n);
        std::transform(nums.begin(), nums.end(), strnums.begin(), [](int x) {
            return std::to_string(x);
        });
        std::sort(strnums.begin(), strnums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        return std::accumulate(strnums.begin(), strnums.end(), string());
    }
};

int main(int argc, char** argv) {

    return 0;
}
