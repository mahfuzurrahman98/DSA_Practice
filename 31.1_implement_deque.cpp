#include <bits/stdc++.h>

class Deque {
  public:
  int *arr;
  int size;
  int front;
  int rear;
  Deque(int n) {
    size = n;
    arr = new int[n];
    front = -1;
    rear = -1;
  }

  // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
  bool pushFront(int x) {
    if (isFull()) {
      return false;
    } else if (isEmpty()) {
      front = rear = 0;
    } else {
      front = front == 0 ? size - 1 : front - 1;
    }

    arr[front] = x;
    return true;
  }

  // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
  bool pushRear(int x) {
    if (isFull()) {
      return false;
    } else if (isEmpty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    arr[rear] = x;
    return true;
  }

  // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
  int popFront() {
    if (isEmpty()) {
      return -1;
    }
    if (front == rear) {
      int data = arr[front];
      front = rear = -1;
      return data;
    }
    int data = arr[front];
    front = (front + 1) % size;
    return data;
  }

  // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
  int popRear() {
    if (isEmpty()) {
      return -1;
    }
    if (front == rear) {
      int data = arr[rear];
      front = rear = -1;
      return data;
    }
    int data = arr[rear];
    //         rear = (rear - 1) % size;
    rear = rear == 0 ? size - 1 : rear - 1;
    return data;
  }

  // Returns the first element of the deque. If the deque is empty, it returns -1.
  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return arr[front];
  }

  // Returns the last element of the deque. If the deque is empty, it returns -1.
  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    return arr[rear];
  }

  // Returns true if the deque is empty. Otherwise returns false.
  bool isEmpty() {
    return front == -1 && rear == -1;
  }

  // Returns true if the deque is full. Otherwise returns false.
  bool isFull() {
    return (rear + 1) % size == front;
  }
};
