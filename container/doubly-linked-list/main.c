#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

Node *head, *tail;

void showAll() {
  // current를 첫 원소의 포인터로 만듦
  Node *current = head->next;

  while (current != tail) {
    printf("Node(data = %d, next = %p)\n", current->data, current->next);
    current = current->next;
  }
}

void insert(int data) {
  // 새로운 노드 포인터 생성
  Node *node = (Node *)malloc(sizeof(Node));

  // 입력받은 데이터 넣기
  node->data = data;

  // head 다음 노드를 current로 잡음
  Node *current = head->next;

  // 오름차순으로 입력할 예정
  // 입력한 값이 current->data의 값 이상이라면 current를 변경
  while (current->data < data && current != tail) {
    current = current->next;
  }

  Node *prev = current->prev;

  // prev -next-> node -next-> current
  prev->next = node;
  node->next = current;

  // prev <-prev- node <-prev- current
  node->prev = prev;
  current->prev = node;
}

void removeFront() {
  // head -next-> nextnode
  Node *node = head->next;
  head->next = node->next;

  // head <-prev- nextnode
  Node *next = node->next;
  next->prev = head;

  free(node);
}

int main(void) {
  head = (Node *)malloc(sizeof(Node));
  tail = (Node *)malloc(sizeof(Node));

  head->prev = head;
  head->next = tail;
  tail->prev = head;
  tail->next = tail;

  insert(3);
  insert(4);
  insert(1);
  insert(2);

  removeFront();

  showAll();

  return 0;
}
