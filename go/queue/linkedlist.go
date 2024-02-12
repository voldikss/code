package main

import "errors"

type node struct {
	data T
	next *node
}

type LinkedListQueue struct {
	front, rear *node
	size        int
}

func NewLinkedListQueue() *LinkedListQueue {
	return &LinkedListQueue{
		front: nil,
		rear:  nil,
		size:  0,
	}
}

func (this *LinkedListQueue) EnQueue(value T) error {
	np := &node{
		data: value,
		next: nil,
	}
	if this.rear != nil {
		this.rear.next = np
	}
	this.rear = np
	if this.front == nil {
		this.front = np
	}
	this.size++
	return nil
}

func (this *LinkedListQueue) DeQueue() (T, error) {
	if this.IsEmpty() {
		return T{}, errors.New("queue is empty")
	}
	result := this.front.data
	this.front = this.front.next
	this.size--
	return result, nil
}

func (this *LinkedListQueue) Front() (T, error) {
	if this.IsEmpty() {
		return T{}, errors.New("queue is empty")
	}
	return this.front.data, nil
}

func (this *LinkedListQueue) Rear() (T, error) {
	if this.IsEmpty() {
		return T{}, errors.New("queue is empty")
	}
	return this.rear.data, nil
}

func (this *LinkedListQueue) Size() int {
	return this.size
}

func (this *LinkedListQueue) IsEmpty() bool {
	return this.size == 0
}

func (this *LinkedListQueue) IsFull() bool {
	return false
}
