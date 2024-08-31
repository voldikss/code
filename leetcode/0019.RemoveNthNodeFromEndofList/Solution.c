#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode *p1 = head;
  struct ListNode *p2 = head;

  for (int i = 0; i < n; ++i) {
    p1 = p1->next;
  }

  if (p1 == NULL)
    return head->next;

  while (p1->next) {
    p1 = p1->next;
    p2 = p2->next;
  }

  struct ListNode *tmp = p2->next;
  p2->next = tmp->next;
  free(tmp);
  return head;
}

int main() {}
