#include <bits/stdc++.h>

class Node {
public:
    int data;
    Node* next;
   
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Queue {
private:
    Node* f;
    Node* r;
    
public:    
    Queue() {
        // Implement the Constructor
        r = NULL;
        f = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return r == NULL && f == NULL;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (isEmpty()) {
            // first push
            r = new Node(data);
            f = r;
            return;
        }
        
        r->next = new Node(data);
        r = r->next;
    }

    int dequeue() {
        // Implement the dequeue() function
        if (isEmpty()) {
            return -1;
        }
        
        if (f == r && f != NULL) {
            // in case front and rear are at the same place
            // we can't move them further
            int peek = f->data;
            f = r = NULL; // get back them to initial state
            return peek;
        }
        
        int peek = f->data;
        f = f->next;        
        return peek;
    }

    int front() {
        // Implement the front() function
        if (isEmpty()) {
            return -1;
        }
        return f->data;
    }
};
