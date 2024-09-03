package main

import (
	"fmt"
	"sort"
)

func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	result := [][]int{}
	left := intervals[0]
	left0 := left[0]
	left1 := left[1]
	right := intervals[0]
	for _, right = range intervals {
		if left1 >= right[0] {
			left1 = max(left1, right[1])
		} else {
			result = append(result, []int{left0, left1})
			left0 = right[0]
			left1 = right[1]
		}
	}

	result = append(result, []int{left0, left1})

	return result
}

func main() {
	// intervals := [][]int{{1, 3}, {2, 6}, {8, 10}, {15, 18}} // [[1,3],[2,6],[8,10],[15,18]]
	intervals := [][]int{{1, 4}, {2, 3}} // [[1,4],[2,3]]
	output := merge(intervals)
	fmt.Println(output)
}
