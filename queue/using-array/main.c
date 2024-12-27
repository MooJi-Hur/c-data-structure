#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define INF 99999

int myQueue[SIZE];
int frontIndex = 0;
int rearIndex = 0;

void addData(int data) {
  if (rearIndex >= SIZE) {
    printf("It's overflow.");
  }

  myQueue[rearIndex++] = data;
}

int removeData() {
  if (frontIndex == rearIndex) {
    printf("It's underflow.");

    return -INF;
  }

  return myQueue[++frontIndex];
}

void show() {
  printf("MyQueue is ...");
  for (int i = frontIndex; i < rearIndex; ++i) {
    printf("%d ", myQueue[i]);
  }
  printf(".");
}

int main(void) {
  addData(1);
  addData(2);
  addData(3);
  addData(4);
  show();
  removeData();
  show();
  return 0;
}
