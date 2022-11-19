//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* l0 = new Node(-1);
        Node* l1 = new Node(-1);
        Node* l2 = new Node(-1);
        
        Node* l0_h = NULL;
        Node* l1_h = NULL;
        Node* l2_h = NULL;
        
        Node* temp = head;
        
        while (temp != NULL) {
            if (temp->data == 0) {
                if (l0 != NULL && l0->data == -1) {
                    l0 = new Node(temp->data);
                    l0_h = l0;
                } 
                else {
                    l0->next = new Node(temp->data);
                    l0 = l0->next;
                }
            } else if (temp->data == 1) {
                if (l1 != NULL && l1->data == -1) {
                    l1 = new Node(temp->data);
                    l1_h = l1;
                } 
                else {
                    l1->next = new Node(temp->data);
                    l1 = l1->next;
                }
            } else {
                if (l2 != NULL && l2->data == -1) {
                    l2 = new Node(temp->data);
                    l2_h = l2;
                } 
                else {
                    l2->next = new Node(temp->data);
                    l2 = l2->next;
                }
                
            }
            temp = temp->next;
        }
        
        temp = NULL;
        
        // Assign next to l0
        if (l1_h != NULL) { // l1 isn't empty
            l0->next = l1_h;
            l1->next = l2_h; // Assign to l1, as we successfully assigned to l0
        } else { // l2 can be empty or not, it doesn't matter
            l0->next = l2_h;
        }
        
        // Assign to head
        if (l0_h != NULL) { // l0 isn't empty
            temp = l0_h;
        } else {  // l1 is empty
            temp = l0->next; // head is either l1 or l2 which simoly next to l0
        }
        
        return temp;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends