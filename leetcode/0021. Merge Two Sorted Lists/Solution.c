#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int data;
  struct ListNode *next;
};

void Print(struct ListNode *l) {
  while (l) {
    printf("%d\n", l->data);
    l = l->next;
  }
}

struct ListNode *Create(int d) {
  struct ListNode *l;
  l = (struct ListNode *)malloc(sizeof(struct ListNode));
  l->data = d;
  l->next = NULL;
  return l;
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *l = Create(0);
  struct ListNode *p = l;
  while (l1 && l2) {
    if (l1->data < l2->data) {
      l->next = l1;
      l1 = l1->next;
    } else {
      l->next = l2;
      l2 = l2->next;
    }
    l = l->next;
  }
  if (l1)
    l->next = l1;
  else
    l->next = l2;

  return p->next;
}

int main() {
  struct ListNode *l1 = Create(1);
  struct ListNode *l2 = Create(2);
  struct ListNode *l3 = Create(3);
  l3->next = NULL;
  l2->next = l3;
  l1->next = l2;

  struct ListNode *l4 = Create(1);
  struct ListNode *l5 = Create(2);
  struct ListNode *l6 = Create(4);
  l6->next = NULL;
  l5->next = l6;
  l4->next = l5;
  // Print(l1);
  // Print(l4);
  struct ListNode *l = mergeTwoLists(l1, l4);
  Print(l);
}
