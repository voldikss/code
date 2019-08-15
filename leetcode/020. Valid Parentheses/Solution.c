#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *data;
  int length;
  int top;
} stack_t;

stack_t *init_stack(void) {
  stack_t *stack = malloc(sizeof(stack_t));
  stack->length = 10;
  stack->data = malloc(stack->length * sizeof(char));
  stack->top = 0;

  return stack;
}

void push(stack_t *s, char ch) {
  s->data[s->top++] = ch;
  if (s->top >= s->length) {
    s->length *= 2;
    s->data = realloc(s->data, s->length);
  }
}

int pop(stack_t *s) {
  if (s->top > 0)
    return s->data[--s->top];
  else
    return 0;
}

bool is_empty(stack_t *s) { return s->top == 0 ? true : false; }

void free_stack(stack_t *s) {
  free(s->data);
  free(s);
}

char parens[3][2] = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

bool is_open_paren(char ch) {
  for (int i = 0; i < 3; i++) {
    if (parens[i][0] == ch)
      return true;
  }
  return false;
}

bool is_matched(char ch1, char ch2) {
  for (int i = 0; i < 3; i++) {
    if (parens[i][0] == ch1 && parens[i][1] == ch2)
      return true;
  }
  return false;
}

bool isValid(char *s) {
  stack_t *stack = init_stack();
  bool flag;

  while (*s) {
    if (is_open_paren(*s)) {
      push(stack, *s);
    } else if (is_empty(stack) || !is_matched(pop(stack), *s))
      return false;
    s++;
  }

  if (*s == '\0')
    flag = is_empty(stack);

  free_stack(stack);

  return flag;
}

int main() {
  char *s = "([}])";
  printf("%d\n", isValid(s));
}
