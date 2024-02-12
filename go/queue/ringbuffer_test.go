package main

import (
	"testing"
)

func TestRingBufferQueue(t *testing.T) {
	queue := NewRingBufferQueue(3)
	if isEmpty := queue.IsEmpty(); !isEmpty {
		t.Errorf("queue should be empty")
	}

	queue.EnQueue(T{Value: 1})
	if result, _ := queue.Front(); result.Value != 1 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "1")
	}
	if result, _ := queue.Rear(); result.Value != 1 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "1")
	}

	queue.EnQueue(T{Value: 2})
	if result, _ := queue.Front(); result.Value != 1 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "1")
	}
	if result, _ := queue.Rear(); result.Value != 2 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "2")
	}

	queue.EnQueue(T{Value: 3})
	if result, _ := queue.Front(); result.Value != 1 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "1")
	}
	if result, _ := queue.Rear(); result.Value != 3 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "3")
	}

	queue.EnQueue(T{Value: 4})
	if result, _ := queue.Front(); result.Value != 1 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "1")
	}
	if result, _ := queue.Rear(); result.Value != 3 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "3")
	}

	if isFull := queue.IsFull(); !isFull {
		t.Errorf("queue should be full")
	}

	if result, _ := queue.DeQueue(); result.Value != 1 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "1")
	}
	if result, _ := queue.Front(); result.Value != 2 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "2")
	}
	if result, _ := queue.Rear(); result.Value != 3 {
		t.Errorf("unexpected value: %s, expected: %s", result.Value, "3")
	}
}
