#include <stdio.h>
#include <stdlib.h>
#define INF 99999

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *front;
  Node *rear;
  int count;
} Queue;

void addQueue(Queue *queue, int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (queue->count == 0) {
    queue->front = node;
  } else {
    queue->rear->next = node;
  }
  queue->rear = node;
  queue->count++;
}

int removeQueue(Queue *queue) {
  if (queue->count == 0) {
    printf("It's underflow.");
    return -INF;
  }

  Node *node = queue->front;
  int data = node->data;

  queue->front = node->next;
  free(node);
  queue->count--;

  return data;
}

void show(Queue *queue) {
  Node *cur = queue->front;
  printf("It's my queue..");

  while (cur != NULL) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf(".\n");
}

int main(void) {
  Queue myQueue;
  myQueue.front = myQueue.rear = NULL;
  myQueue.count = 0;

  addQueue(&myQueue, 1);
  addQueue(&myQueue, 2);
  addQueue(&myQueue, 3);
  addQueue(&myQueue, 4);
  addQueue(&myQueue, 5);
  show(&myQueue);
  removeQueue(&myQueue);
  show(&myQueue);
  return 0;
}
