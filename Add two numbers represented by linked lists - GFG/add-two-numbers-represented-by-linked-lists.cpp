//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    struct Node* reverse(Node* ll) {
        struct Node* prevNode = NULL;
        struct Node* curNode = ll;
        struct Node* nextNode = NULL;
    
        while (curNode != NULL) {
            nextNode = curNode->next;
            curNode->next = prevNode;
    
            prevNode = curNode;
            curNode = nextNode;
        }
        return prevNode;
    }
  
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node* prevNode = NULL;
        struct Node* tempNode;

        first = reverse(first);
        second = reverse(second);
        
        int num1, num2, carry = 0, z, keep;
        while (!(first == NULL && second == NULL)) {
            if (first == NULL) {
                num1 = 0;
            } else {
                num1 = first->data;
            }
            if (second == NULL) {
                num2 = 0;
            } else {
                num2 = second->data;
            }
    
            z = num1 + num2 + carry;
            keep = z % 10;
            carry = z / 10;
            // cout << keep << " ";
            tempNode = new Node(keep);
            tempNode->next = prevNode;
            prevNode = tempNode;
    
            if (first != NULL) {
                first = first->next;
            }
            if (second != NULL) {
                second = second->next;
            }
        }

        if (carry > 0) {
            prevNode = new Node(carry);
            prevNode->next = tempNode;
            tempNode = prevNode;
        }
        return tempNode;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends