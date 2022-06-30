#include <stdio.h>

int factorial(int n) {
  int result = 1;
  int i;

  for (i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}

// iterate to recursive
int recur_fac(int n) {
  // terminate condition
  if (n == 1) {
    return 1;
  } else {
    return n * recur_fac(n - 1);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  printf("%d\n", factorial(n));
  printf("%d\n", recur_fac(n));

  return 0;
}