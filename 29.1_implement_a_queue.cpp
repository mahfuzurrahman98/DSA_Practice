#include <bits/stdc++.h> 
class Queue {
private:
    int* arr;
    int size, f, r;
public:
    Queue() {
        // Implement the Constructor
        arr = new int [9999];
        size = 0;
        f = -1;
        r = -1;
    }
    
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return size == 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (isEmpty()) { // first push
            f = 0;
        }
        r++;
        arr[r] = data;
        size++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if (isEmpty()) {
            return -1;
        }
        if (size == 1 && f == r) { 
            // in case front and rear get the same position
            // and queue has only one element left
            int ret = arr[f];
            f = r = -1, size = 0; // get back to the initial state
            return ret;
        }
        int ret = arr[f];
        f++;
        size--;
        return ret;
    }

    int front() {
        // Implement the front() function
        if (isEmpty()) {
            return -1;
        }
        return arr[f];
    }
};
