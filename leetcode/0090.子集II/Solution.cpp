#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, nums, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int depth) {
        if (depth > nums.size()) return;
        res.push_back(path);
        for (int i = depth; i < nums.size(); i++) {
            if (i > depth && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            dfs(res, path, nums, i + 1);
            path.pop_back();
        }
    }
};

int main(int argc, char** argv) {
    return 0;
}
