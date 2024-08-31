#include <iostream>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, uint>> pq;
        for (int i = 0; i < k; i++) {
            pq.emplace(nums[i], i);
        }
        vector<int> result = {pq.top().first};
        for (int i = k; i < nums.size(); i++) {
            while (pq.top().second <= i - k && !pq.empty()) {
                pq.pop();
            }
            pq.emplace(nums[i], i);
            result.push_back(pq.top().first);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto result = s.maxSlidingWindow(nums, 3);
    for (auto j = 0; j < result.size(); j++) {
        cout << result[j] << " ";
    }
    return 0;
}
