package main

import (
	"fmt"
	"slices"
)

func maxSubArray(nums []int) int {
	dp := make([]int, len(nums))
	dp[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		dp[i] = max(dp[i-1]+nums[i], nums[i])
	}
	return slices.Max(dp)
}

func main() {
	nums := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	output := maxSubArray(nums)
	fmt.Println(output)
}
