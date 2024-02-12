package main

import (
	"testing"
)

func TestChannelQueue(t *testing.T) {
	queue := NewChannelQueue(3)

	queue.EnQueue(T{Value: 1})
	queue.EnQueue(T{Value: 2})
	queue.EnQueue(T{Value: 3})

	if err := queue.EnQueue(T{Value: 4}); err == nil {
		t.Errorf("queue is full, should return error")
	}

	if result, _ := queue.DeQueue(); result.Value != 1 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "1")
	}

	if result, _ := queue.DeQueue(); result.Value != 2 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "2")
	}

	if result, _ := queue.DeQueue(); result.Value != 3 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "3")
	}

	if _, err := queue.DeQueue(); err == nil {
		t.Errorf("queue is empty, should return error")
	}
}
