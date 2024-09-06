package main

import (
	"fmt"
)

func productExceptSelf(nums []int) []int {
	leftProducts := make([]int, len(nums))
	rightProducts := make([]int, len(nums))
	left := 1
	right := 1
	for i := range nums {
		left *= nums[i]
		leftProducts[i] = left
		right *= nums[len(nums)-1-i]
		rightProducts[len(nums)-1-i] = right
	}
	result := make([]int, len(nums))
	for i := range result {
		if i == 0 {
			result[i] = rightProducts[1]
		} else if i == len(nums)-1 {
			result[i] = leftProducts[len(nums)-2]
		} else {
			result[i] = leftProducts[i-1] * rightProducts[i+1]
		}
	}
	return result
}

func main() {
	input := []int{1, 2, 3, 4}
	output := productExceptSelf(input) // [24 12 8 6]
	fmt.Println(output)
}
