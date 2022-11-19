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
