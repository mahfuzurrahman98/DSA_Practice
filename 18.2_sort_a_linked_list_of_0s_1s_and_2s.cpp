class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        
        Node* temp = head;
        
        while (temp != NULL) {
            if (temp->data == 0) {
                zeroTail->next = new Node(0);
                zeroTail = zeroTail->next;
            } else if (temp->data == 1) {
                oneTail->next = new Node(1);
                oneTail = oneTail->next;
            } else {
                twoTail->next = new Node(2);
                twoTail = twoTail->next;
            }
            temp = temp->next;
        }
        
        if (oneHead->next != NULL) {
            zeroTail->next = oneHead->next;
        } else {
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        temp = zeroHead->next;
        return temp;
    }
};
