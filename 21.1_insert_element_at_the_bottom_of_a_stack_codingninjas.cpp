void rec(stack<int>& myStack, int i, int n, int x) {
    if (i == n) {
        myStack.push(x);
        return;
    }
    int top = myStack.top();
    myStack.pop();
    rec(myStack, i + 1, n, x);
    myStack.push(top);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    int n = myStack.size();
    rec(myStack, 0, n, x);
    
    return myStack;
}
