// 竟然能过...
function subarraySum(nums: number[], k: number): number {
    let result = 0
    for (let i = 0; i < nums.length; i++) {
        let sum = 0
        for (let j = i; j < nums.length; j++) {
            sum += nums[j]
            if (sum === k) {
                result += 1
            }
        }
    }
    return result
};
