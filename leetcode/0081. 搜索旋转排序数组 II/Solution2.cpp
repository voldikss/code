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
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;

            if (nums[left] == nums[right]) {
                left++;
                continue;
            }

            if (nums[mid] <= nums[right]) {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if (nums[mid] > target && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};

int main(int argc, char** argv) {

    return 0;
}
