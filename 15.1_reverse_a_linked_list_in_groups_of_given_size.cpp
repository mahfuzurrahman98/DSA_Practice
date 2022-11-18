class Solution
{
    public:
    struct node *reverse (struct node *head, int k) {
        struct node* curNode = head;
        struct node* prevNode = NULL;
        struct node* nextNode;
        int counter = 0;
    
        while (counter < k && curNode != NULL) {
          nextNode = curNode->next;
          curNode->next = prevNode;
          prevNode = curNode;
          // iteration
          curNode = nextNode;
    
          counter++;
        }
        
        if (nextNode != NULL) {
          head->next = reverse(nextNode, k);
        }
        return prevNode;
    }
};
