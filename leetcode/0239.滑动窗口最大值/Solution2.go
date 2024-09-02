package main

import (
	"fmt"
)

func maxSlidingWindow(nums []int, k int) []int {
	q := []int{}

	for i := 0; i < k; i++ {
		for len(q) > 0 && nums[i] >= nums[q[len(q)-1]] {
			q = q[:len(q)-1]
		}
		q = append(q, i)
	}

	result := []int{nums[q[0]]}

	for i := k; i < len(nums); i++ {
		for len(q) > 0 && nums[i] >= nums[q[len(q)-1]] {
			q = q[:len(q)-1]
		}
		q = append(q, i)

		for q[0] <= i-k {
			q = q[1:]
		}
		result = append(result, nums[q[0]])
	}

	return result
}

func main() {
	// nums := []int{1, 3, -1, -3, 5, 3, 6, 7}
	// output := maxSlidingWindow(nums, 3)
	// nums := []int{1, -1}
	// output := maxSlidingWindow(nums, 1)
	nums := []int{1, 3, 1, 2, 0, 5}
	output := maxSlidingWindow(nums, 3) // [3,3,2,5]
	fmt.Println(output)
}
