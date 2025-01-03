#include <stdio.h>
#include <stdlib.h>

#define INF 99999

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Stack {
  Node* top;
} Stack;

void push(Stack* stack, int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = stack->top;
  stack->top = node;
}

int pop(Stack* stack) {
  if (stack->top == NULL) {
    printf("It's underflow. \n");
    return -INF;
  }
  Node* node = stack->top;

  int data = node->data;
  stack->top = node->next;
  free(node);
  return data;
}

void show(Stack* stack) {
  Node* cur = stack->top;
  printf("It's top. \n");

  while (cur != NULL) {
    printf("%d\n", cur->data);
    cur = cur->next;
  }

  printf("It's bottom. \n");
}

int main(void) {
  Stack myStack;
  myStack.top = NULL;

  push(&myStack, 1);
  push(&myStack, 2);
  push(&myStack, 3);
  push(&myStack, 4);
  push(&myStack, 5);
  push(&myStack, 6);
  pop(&myStack);
  push(&myStack, 7);
  show(&myStack);
  return 0;
}
