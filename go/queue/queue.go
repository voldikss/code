package main

import "fmt"

type Queue interface {
	EnQueue(T) error
	DeQueue() (T, error)
	Front() (T, error)
	Rear() (T, error)
	Size() int
	IsFull() bool
	IsEmpty() bool
}

func main() {
	var queue Queue
	queue = NewRingBufferQueue(3)
	fmt.Println(queue.Size())
}
