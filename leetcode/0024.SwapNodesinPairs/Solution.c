#include <stdio.h>

typedef struct ListNode *List;
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head) {
  if (head == NULL || head->next == NULL)
    return head;

  // List tmp = head;
  // head = head->next;
  // tmp->next = swapPairs(head->next->next);
  // head->next = tmp;

  // return head;

  // better
  List next = head->next;
  head->next = swapPairs(next->next);
  next->next = head;
  return next;
}

int main() {}
