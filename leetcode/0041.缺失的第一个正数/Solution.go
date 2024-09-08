package main

import (
	"fmt"
	"slices"
)

func firstMissingPositive(nums []int) int {
	plus1 := make([]int, len(nums))
	m := make(map[int]bool, len(nums))
	for i, v := range nums {
		plus1[i] = nums[i] + 1
		m[v] = true
	}
	if _, ok := m[1]; !ok {
		return 1
	}
	n := slices.Max(plus1)
	for _, v := range plus1 {
		if v <= 0 {
			continue
		}
		if _, ok := m[v]; !ok {
			n = min(n, v)
		}
	}
	return n
}

func main() {
	input := []int{1, 2, 0} // 3
	output := firstMissingPositive(input)
	fmt.Println(output)
}
