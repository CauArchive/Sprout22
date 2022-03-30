// Week 02
#include <stdio.h>

// 콘솔창에 별 찍어보기
// ****
//  ***
//   **
//    *
// https://www.acmicpc.net/problem/2441

int main() {
  int n = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      printf(" ");
    }
    for (int j = 0; j < n - i; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}