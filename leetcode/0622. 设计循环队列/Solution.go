type MyCircularQueue struct {
	buffer []int
	front  int
	rear   int
}

func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		buffer: make([]int, k+1),
		front:  0,
		rear:   0,
	}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.IsFull() {
		return false
	}
	this.buffer[this.rear] = value
	this.rear = (this.rear + 1) % len(this.buffer)
	return true
}

func (this *MyCircularQueue) DeQueue() bool {
	if this.IsEmpty() {
		return false
	}
	this.front = (this.front + 1) % len(this.buffer)
	return true
}

func (this *MyCircularQueue) Front() int {
	if this.IsEmpty() {
		return -1
	}
	return this.buffer[this.front]
}

func (this *MyCircularQueue) Rear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.buffer[(this.rear-1+len(this.buffer))%len(this.buffer)]
}

func (this *MyCircularQueue) IsEmpty() bool {
	return this.front == this.rear
}

func (this *MyCircularQueue) IsFull() bool {
	return (this.rear+1)%len(this.buffer) == this.front
}
