#include <bits/stdc++.h> 
class CircularQueue{
    private:
    int* q;
    int front, rear, MX;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        MX = n;
        q = new int[MX];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value) {
        // Write your code here.
        if ((rear + 1) % MX == front) {
            return false;
        }
        
        if (front == -1 && rear == -1) { // initail state
            front = rear = 0;
            q[rear] = value;
            return true;
        }
        
        rear = (rear + 1) % MX;
        q[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if (front == -1 && rear == -1) { // initail state
            return -1;
        }
        
        if (front == rear) { // only one element is present
            int peek = q[front];
            front = rear = -1;
            return peek;
        }
        
        int peek = q[front];
        front = (front + 1) % MX;
        return peek;
    }
};
