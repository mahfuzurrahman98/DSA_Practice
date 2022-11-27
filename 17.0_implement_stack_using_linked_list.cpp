//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends


//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    // alwyas push at the begining
    StackNode* temp = new StackNode(x);
    if (top == NULL) { // first push
        top = temp;
    } else {
        temp->next = top; // insert at the begining
        top = temp; // change top to temp
    }
    
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if (top == NULL) { // stack is empty
        return -1;
    }
    int data = top->data;
    top = top->next;
    return data;
}

