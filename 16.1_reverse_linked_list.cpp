class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* curNode = head;
    ListNode* prevNode = NULL;
    ListNode* nextNode;

    while (curNode != NULL) {
      nextNode = curNode->next;
      curNode->next = prevNode;

      prevNode = curNode;
      curNode = nextNode; 
    }

    return prevNode;
  }
};
