package main

import "fmt"

func rotate(nums []int, k int) {
	nums1 := make([]int, len(nums))
	for i, n := range nums {
		nums1[(i+k)%len(nums)] = n
	}
	copy(nums, nums1)
}

func main() {
	input := []int{1, 2, 3, 4, 5, 6, 7}
	rotate(input, 3)
	fmt.Println(input)
}
