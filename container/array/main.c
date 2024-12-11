#include <stdio.h>
#include <stdlib.h>
#define INF 10

int myArray[INF];
int count = 0;

void show() {
  for (int i = 0; i < count; ++i) {
    printf("%d \n", myArray[i]);
  }
}

// 원소의 수와 값 추가가 간결하게 이루어짐
void addBack(int element) {
  myArray[count] = element;
  ++count;
}

// 뒤에서부터 바로 앞 값을 복사해가면서 자리를 만들어냄
void addFront(int element) {
  for (int i = count; i > 0; --i) {
    myArray[i] = myArray[i - 1];
  }
  myArray[0] = element;
  ++count;
}

// 지워진 값은 다음 값으로 덮어쓰고, 전체 크기를 관리
void removeAt(int index) {
  for (int i = index; i < count; ++i) {
    myArray[i] = myArray[i + 1];
  }
  --count;
}

int main(void) {
  addBack(7);
  addBack(9);
  addFront(8);
  addFront(10);
  removeAt(1);
  show();
  return 0;
}
