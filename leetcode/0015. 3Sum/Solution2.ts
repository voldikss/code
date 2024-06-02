function threeSum(nums: number[]): number[][] {
    nums.sort((x, y) => x - y)
    // console.log(nums)
    const result: number[][] = []
    for (let i = 0; i < nums.length; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue
        if (nums[i] > 0) break
        let k = nums.length - 1
        const target = -nums[i]
        for (let j = i + 1; j < k; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue
            while (nums[j] + nums[k] > target && j < k) {
                k--
            }
            if (j === k) break
            if (nums[j] + nums[k] === target) {
                result.push([nums[i], nums[j], nums[k]])
                continue
            }
            // if (nums[j] + nums[k] < target) {
            //     break
            // }
        }
    }
    return result
};
