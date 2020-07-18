#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val);

int main() {}

struct ListNode *removeElements(struct ListNode *head, int val) {
  while (head) {
    if (head->val == val) {
      struct ListNode *tmp = head;
      head = head->next;
      free(tmp);
    } else
      break;
  }
  if (head == NULL)
    return NULL;
  if (head->next == NULL)
    return head;

  struct ListNode *p = head;
  struct ListNode *q = p->next;
  while (q != NULL) {
    if (q->val == val) {
      struct ListNode *tmp = q;
      p->next = q->next;
      q = q->next;
      free(tmp);
    } else {
      p = p->next;
      q = q->next;
    }
  }
  return head;
}

struct ListNode *removeElements_v2(struct ListNode *head, int val) {
  if (head == NULL)
    return NULL;
  head->next = removeElements_v2(head->next, val);
  return head->val == val ? head->next : head;
}
