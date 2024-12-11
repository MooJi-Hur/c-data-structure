#include <stdio.h>
#include <stdlib.h>

/**
 * typedef : 구조체에 별칭을 붙임
 * 앞으로는 struct Node가 아니라 Node로 바로 구조체 사용
 * struct Node :
 * Node라는 이름의 구조체 정보값(data)과 다음 노드의 주소값을 저장한
 * 포인터(next)
 */
typedef struct Node {
  int data;
  // 재귀 구조를 만듦
  struct Node *next;

  // 구조체 별칭
} Node;

// Node *head 변수명이 head, Node 구조체를 가리키는 포인터
// struct Node *head;
Node *head;

void addFront(Node *root, int data) {
  /**
   * malloc : 입력받은 크기의 메모리를 힙 영역에 할당, 메모리 시작 주소를 반환
   * 반환 주소 값은 void * type (Node *) : void * 타입을 Node * 타입으로 형 변환
   * node는 Node 구조체를 가리키는 포인터
   */
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;

  // [root] -next-> [기존 노드]
  // [새 노드] -next-> [기존 노드]
  // root 노도의 next에 있던 주소값을 node의 next로 복사
  node->next = root->next;

  // [root] -next-> [새 노드] -next-> [기존 노드]
  // 기존 root 노드의 next의 값은 새로 추가하는 노드의 주소 값으로 변경
  root->next = node;
}

void removeFront(Node *root) {
  /**
   * 입력한 데이터 3, 2, 4
   * root (data = 0, next = 주소 1)
   * 주소 1이 가리키는 노드 (data = 4, next = 주소 2)
   * 주소 2가 가리키는 노드 (data = 2, next = 주소 3)
   * 주소 3이 가리키는 노드 (data = 3, next = null 주소)
   *
   * front = 주소 1
   */
  Node *front = root->next;

  /**
   * front->next == 주소 2
   *
   * root->next를 주소 2로 할당,
   * root (data = 0, next = 주소 2) : data를 별도로 할당한 것은 아님
   * 주소 2가 가리키는 노드 (data = 2, next = 주소 3)
   * 주소 3이 가리키는 노드 (data = 3, next = null 주소)
   */
  root->next = front->next;
  free(front);
}

void freeAll(Node *root) {
  // head의 next부터 시작하게 됨
  // root->next는 현재 첫 원소 노드의 주소
  Node *current = root->next;

  // 마지막 노드의 next는 NULL
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }

  free(root);  // head 노드도 해제하게 됨
}

void showAll(Node *root) {
  // head의 다음 노드 주소 (첫 원소)
  Node *current = root->next;

  while (current != NULL) {
    printf("Node(data = %d, next = %p)\n", current->data, current->next);
    current = current->next;
  }
}

int main(void) {
  head = (Node *)malloc(sizeof(Node));
  head->next = NULL;

  addFront(head, 3);
  addFront(head, 2);
  addFront(head, 4);

  printf("Before removing front:\n");
  showAll(head);

  removeFront(head);

  printf("\nAfter removing front:\n");

  showAll(head);

  freeAll(head);
  return 0;
}
