#include <stdio.h>

// #설명
// 만약 배열에 담긴 숫자가 양수일때만
// 별을 찍고 싶다면 어떻게 해야할까?

int main(void) {
  int n[5] = {3, 1, 0, 2, 4};

  for (int i = 0; i < 5; i++) {
    if (n[i] % 2 == 0) {
      for (int j = 0; j < i + 1; j++) {
        printf("*");
      }
    }
    printf("\n");
  }

  return 0;
}