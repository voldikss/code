package main

import (
	"fmt"
)

func minWindow(s string, t string) string {
	result := ""

	counter := make(map[byte]int)
	target := make(map[byte]int)
	for i := 0; i < len(t); i++ {
		target[t[i]]++
	}

	check := func() bool {
		for k, v := range target {
			if counter[k] < v {
				return false
			}
		}
		return true
	}

	lp := 0
	rp := -1 // 如果这里也初始化为 0 的话，我下面又要 rp--，索性从 -1 开始了
	for lp < len(s) {
		// 不满足条件则一直移动右指针
		for !check() && rp+1 < len(s) {
			rp++
			counter[s[rp]]++
		}
		// 如果上一步是因为满足条件而退出循环的
		if check() {
			if rp-lp < len(result) || len(result) == 0 {
				result = s[lp : rp+1]
			}
		}
		// 减去左指针位置的值，要开始移动左指针了
		counter[s[lp]]--
		lp++
		// 直到左指针遇到一个符合条件的位置
		for lp < len(s) {
			if _, exists := target[s[lp]]; exists {
				break
			}
			lp++
		}
	}
	return result
}

func main() {
	s := "ADOBECODEBANC"
	t := "ABC" // "BANC"
	output := minWindow(s, t)
	fmt.Println(output)
}
