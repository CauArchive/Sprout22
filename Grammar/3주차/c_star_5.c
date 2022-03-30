#include <stdio.h>

// #설명
// https://www.acmicpc.net/problem/2442

int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i = i + 1) {
    for (int j = 0; j < n - i - 1; j = j + 1) {
      printf(" ");
    }
    for (int k = 0; k < 2 * i + 1; k = k + 1) {
      printf("*");
    }
    printf("\n");
  }
}