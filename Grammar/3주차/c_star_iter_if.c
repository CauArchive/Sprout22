#include <stdio.h>

// #설명
// 만약 배열에 담긴 숫자가 양수일때만
// 별을 찍고 싶다면 어떻게 해야할까?

int main(void) {
  int n[5] = {-1, 1, 0, 2, 4};

  for (int i = 0; i < 5; i++) {
    if ("여기에 코드를 채워주세요") {
      for (int j = 0; j < i + 1; j++) {
        printf("*");
      }
    }
    printf("\n");
  }

  return 0;
}