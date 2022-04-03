// Week 03
#include <stdio.h>

// 반복문을 이용해서
// 콘솔창에 별 찍어보기
//    *
//   **
//  ***
// ****
// https://www.acmicpc.net/problem/2440

// Hint: for(int i=4;i>=1;i--){}

int main() {
  int n = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      printf(" ");
    }
    for (int j = 0; j < i + 1; j++) {
      printf("*");
    }
    printf("\n");
  }
}