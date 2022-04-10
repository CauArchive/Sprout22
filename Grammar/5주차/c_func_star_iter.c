// Week 04
#include <stdio.h>

// Print on Console
// *
// **
// ***
// ****
// https://www.acmicpc.net/problem/2438

void solve(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  int n = 0;
  scanf("%d", &n);
  solve(n);
  return 0;
}