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
        return f == r && f == -1;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (isEmpty()) { // first push
            f = 0;
        }
        r++;
        arr[r] = data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if (isEmpty()) {
            return -1;
        }
        if (f == r && f != -1) { 
            // in case front and rear get the same position
            // and queue has only one element left
            int ret = arr[f];
            f = r = -1; // get back to the initial state
            return ret;
        }
        int ret = arr[f];
        f++;
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
