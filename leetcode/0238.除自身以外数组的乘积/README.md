```cpp
// from https://leetcode.cn/problems/product-of-array-except-self/solutions/272369/chu-zi-shen-yi-wai-shu-zu-de-cheng-ji-by-leetcode-/comments/2374485
std::vector<int> productExceptSelf2(std::vector<int>& nums) {
    std::vector<int> answer(nums.size(), 1);
    int left = 0, right = nums.size() - 1;
    int lp = 1, rp = 1;
    while (right >= 0 && left < nums.size()) {
        answer[right] *= rp;
        answer[left] *= lp;
        lp *= nums[left++];
        rp *= nums[right--];
    }
    return answer;
}
```
