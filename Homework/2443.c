#include <math.h>
#include <stdio.h>

// #설명
// https://www.acmicpc.net/problem/2443

int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n - i - 1; j++) {
      printf(" ");
    }
    for (int k = 0; k < 2 * i + 1; k++) {
      printf("*");
    }
    printf("\n");
  }
}