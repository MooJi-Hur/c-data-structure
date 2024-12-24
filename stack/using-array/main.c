#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define INF 9999

// 배열로 스택을 구현
int stack[SIZE];

// 자료 입출력을 위한 top 인덱스
int top = -1;

void push(int data) {
  if (top == SIZE - 1) {
    printf("Stack overflow \n");
    return;
  }

  stack[++top] = data;
}

int pop() {
  if (top == -1) {
    printf("Stack underflow \n");

    // 함수의 반환 자료 유형이 int이므로 -INF를 설정하여 오류임을 나타냄
    return -INF;
  }

  return stack[--top];
}

void show() {
  printf("Top \n");

  for (int i = top; i >= 0; --i) {
    printf("%d\n", stack[i]);
  }

  printf("Bottom \n");
}
int main(void) {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  pop();
  push(6);
  show();
  return 0;
}
