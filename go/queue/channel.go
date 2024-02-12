package main

import "errors"

type ChannelQueue struct {
	elements chan T
}

func NewChannelQueue(size uint) *ChannelQueue {
	return &ChannelQueue{
		elements: make(chan T, size),
	}
}

func (this *ChannelQueue) EnQueue(value T) error {
	select {
	case this.elements <- value:
		return nil
	default:
		return errors.New("queue is full")
	}
}

func (this *ChannelQueue) DeQueue() (T, error) {
	select {
	case result := <-this.elements:
		return result, nil
	default:
		return T{}, errors.New("queue is empty")
	}
}
