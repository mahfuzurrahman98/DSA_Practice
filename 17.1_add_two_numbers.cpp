class Solution {
private:
  ListNode* reverse(ListNode* ll) {
    ListNode* prevNode = NULL;
    ListNode* curNode = ll;
    ListNode* nextNode = NULL;

    while (curNode != NULL) {
      nextNode = curNode->next;
      curNode->next = prevNode;

      prevNode = curNode;
      curNode = nextNode;
    }

    return prevNode;
  }
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {    
    ListNode* prevNode = NULL;
    ListNode* tempNode;

    int num1, num2, carry = 0, z, keep;
    while (!(l1 == NULL && l2 == NULL)) {
      if (l1 == NULL) {
        num1 = 0;
      } else {
        num1 = l1->val;
      }
      if (l2 == NULL) {
        num2 = 0;
      } else {
        num2 = l2->val;
      }

      z = num1 + num2 + carry;
      keep = z % 10;
      carry = z / 10;
      
      tempNode = new ListNode(keep, prevNode);
      prevNode = tempNode;

      if (l1 != NULL) {
        l1 = l1->next;
      }
      if (l2 != NULL) {
        l2 = l2->next;
      }
    }

    if (carry > 0) {
      prevNode = new ListNode(carry, NULL);
      prevNode->next = tempNode;
      tempNode = prevNode;
    }
    return reverse(tempNode);
  }
};
