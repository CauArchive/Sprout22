#include <stdio.h>
#include <stdlib.h>  // malloc, free 함수가 선언된 헤더 파일

void print(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int* num;
  // malloc
  num = (int*)malloc(sizeof(int) * 4);

  for (int i = 0; i < 4; i++) {
    num[i] = i;
  }
  print(num, 4);

  int num_2[4] = {0, 1, 2, 3};
  print(num_2, 4);

  free(num);

  return 0;
}