class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) {
      return head;
    }

    ListNode* curNode = head;

    while (curNode != NULL) {
      if (curNode->next != NULL && curNode->val == curNode->next->val) {
        // same, delete
        curNode->next = curNode->next->next;
      } else {
        curNode = curNode->next;
      }
    }

    return head;
  }
};
