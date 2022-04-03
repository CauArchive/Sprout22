// Week 04
#include <stdio.h>

// Print on Console
//    *
//   **
//  ***
// ****
// https://www.acmicpc.net/problem/2440
// Hint: for(int i=4;i>=1;i--){}

void solve(int n) {
  // do something
}

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