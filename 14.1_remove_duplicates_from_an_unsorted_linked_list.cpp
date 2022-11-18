
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        map<int, bool> vis;
        
        if (head == NULL) {
            return head;
        }
        
        Node* curNode = head;
        Node* prevNode = NULL;
        Node* nextNode = NULL;
        
        while (curNode != NULL) {
            if (vis[curNode->data]) {
                nextNode = curNode->next;
                curNode = prevNode;
                curNode->next = nextNode;
            }
            else {
                vis[curNode->data] = true;
                prevNode = curNode;
            }
            curNode = curNode->next;
        }
        
        return head;
    }
};
