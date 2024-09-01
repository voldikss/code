package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	index int
	value int
}

type PriorityQueue []Item

func (p PriorityQueue) Less(i, j int) bool {
	return p[i].value > p[j].value
}

func (p PriorityQueue) Len() int {
	return len(p)
}

func (p PriorityQueue) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// 模拟 Top 方法
func (p PriorityQueue) Top() any {
	x := p.Pop()
	p.Push(x)
	return x
}

func (p PriorityQueue) IsEmpty() bool {
	return p.Len() == 0
}

func (p *PriorityQueue) Push(x any) {
	*p = append(*p, x.(Item))
}

func (p *PriorityQueue) Pop() any {
	old := *p
	n := len(old)
	retval := old[n-1]
	*p = old[0 : n-1]
	return retval
}

func maxSlidingWindow(nums []int, k int) []int {
	pq := &PriorityQueue{}
	heap.Init(pq)
	for i := 0; i < k; i++ {
		heap.Push(pq, Item{value: nums[i], index: i})
	}

	result := []int{}

	// 要从 k-1 开始遍历，是因为 pq 没有类似于 .top() 的方法
	for i := k - 1; i < len(nums); i++ {
		// 先把当前的新进来的元素 push 进去
		heap.Push(pq, Item{index: i, value: nums[i]})
		for true {
			top := heap.Pop(pq).(Item)
			if top.index > i-k {
				result = append(result, top.value)
				// 因为没有类似于 .top() 的方法，因此此处再 push 回去
				heap.Push(pq, top)
				break
			}
		}
	}

	return result
}

func main() {
	nums := []int{1, 3, -1, -3, 5, 3, 6, 7}
	output := maxSlidingWindow(nums, 3)
	fmt.Println(output)
}
