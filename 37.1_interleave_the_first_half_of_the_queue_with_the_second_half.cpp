#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    stack<int> st;
    int n = q.size();
    
    // Q: 10 20 30 40 50 60 70 80 90 100
    // St: 
    
    for (int i = 0; i < n / 2; i++) { // push first half to stack
        st.push(q.front());
        q.pop();
    }
    // Q: 60 70 80 90 100
    // St: 10 20 30 40 50
    
    while (!st.empty()) { // enqueue back stack data to queue
        q.push(st.top());
        st.pop();
    }
    // Q: 60 70 80 90 100 50 40 30 20 10
    // St:
    
    for (int i = 0; i < n / 2; i++) { // enqueue back first hallf of the queue
        q.push(q.front());
        q.pop();
    }
    // Q: 50 40 30 20 10 60 70 80 90 100
    // St: 
    
    for (int i = 0; i < n / 2; i++) { // push first half to stack
        st.push(q.front());
        q.pop();
    }
    // Q: 60 70 80 90 100
    // St: 50 40 30 20 10
    
    while (!st.empty()) { // push one from stack then one from q
        q.push(st.top());
        st.pop();
        
        q.push(q.front());
        q.pop();
    }
    // Q: 10 60 20 70 30 80 40 90 50 100
    // St: 
}
