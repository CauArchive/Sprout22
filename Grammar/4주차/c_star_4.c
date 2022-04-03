// Week 04
#include <stdio.h>

// Print on Console
// ****
//  ***
//   **
//    *
// https://www.acmicpc.net/problem/2441

void solve(int n) {
  // do something
}

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