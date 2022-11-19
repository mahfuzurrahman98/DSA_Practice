#include <bits/stdc++.h> 

void rec(stack<int>& myStack, int x) {
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }
    int top = myStack.top();
    myStack.pop();
    rec(myStack, x);
    myStack.push(top);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    int n = myStack.size();
    rec(myStack, x);
    
    return myStack;
}

