package main

import "errors"

type RingBufferQueue struct {
	elements    []T
	front, rear int
}

func NewRingBufferQueue(size uint) *RingBufferQueue {
	return &RingBufferQueue{
		elements: make([]T, size+1),
	}
}

func (this *RingBufferQueue) EnQueue(value T) error {
	if this.IsFull() {
		return errors.New("queue is full")
	}
	this.elements[this.rear] = value
	this.rear = (this.rear + 1) % len(this.elements)
	return nil
}

func (this *RingBufferQueue) DeQueue() (T, error) {
	if this.IsEmpty() {
		return T{}, errors.New("queue is empty")
	}
	result := this.elements[this.front]
	this.front = (this.front + 1) % len(this.elements)
	return result, nil
}

func (this *RingBufferQueue) Front() (T, error) {
	if this.IsEmpty() {
		return T{}, errors.New("queue is empty")
	}
	return this.elements[this.front], nil
}

func (this *RingBufferQueue) Rear() (T, error) {
	if this.IsEmpty() {
		return T{}, errors.New("queue is empty")
	}
	return this.elements[this.rear-1+len(this.elements)%len(this.elements)], nil
}

func (this *RingBufferQueue) Size() int {
	return len(this.elements)
}

func (this *RingBufferQueue) IsEmpty() bool {
	return this.rear == this.front
}

func (this *RingBufferQueue) IsFull() bool {
	return (this.rear+1)%len(this.elements) == this.front
}
