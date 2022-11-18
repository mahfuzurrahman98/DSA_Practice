class Solution {
public:
  int lengthOfLinkedList(ListNode* head) {
    ListNode *curNode = head;
    int len = 0;

    while (curNode != NULL) {
      curNode = curNode->next;
      len++;
    }
    return len;
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curNode = head;
    ListNode* prevNode = NULL;
    ListNode* nextNode;
    int counter = 0;

    if (lengthOfLinkedList(head) < k) {
      return head;
    }

    while (counter < k && curNode != NULL) {
      nextNode = curNode->next;
      curNode->next = prevNode;
      prevNode = curNode;
      // iteration
      curNode = nextNode;

      counter++;
    }    
    
    if (nextNode != NULL) {
      head->next = reverseKGroup(nextNode, k);
    }
    return prevNode;
  }
};
