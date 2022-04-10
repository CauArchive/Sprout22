// Week 02
#include <stdio.h>

int main(void) {
  int n[5] = {-1, 1, 0, 2, 4};

  for (int i = 0; i < 5; i++) {
    if (n[i] > 0) {
      printf("%d is positive number\n", n[i]);
    } else if (n[i] < 0) {
      printf("%d is negative number\n", n[i]);
    } else {
      printf("%d is 0\n", n[i]);
    }
  }

  return 0;
}